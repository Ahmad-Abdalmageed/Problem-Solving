class Solution {
public:
// LEETCODE: 210. Course Schedule II
vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
  std::vector<std::vector<int>> preqMap(numCourses);
  std::vector<int> courseDegrees(numCourses);

  // Preparing Adjacency List
  for (auto const &preq : prerequisites)
  {
    preqMap[preq[1]].push_back(preq[0]);
    courseDegrees[preq[0]]++;
  }

  // Using a Queue for BFS Solution
  std::queue<int> courseOrder;
  for (int course = 0; course < numCourses; course++)
  {
    if (!courseDegrees[course])
      courseOrder.push(course);
  }

  // Case Cycle Exists
  if (courseOrder.empty())
    return {};

  // Topological Sorting --- Adding Courses with Degree Zero First and updateing
  // the Current Course Order Queue
  std::vector<int> order;
  while (!courseOrder.empty())
  {
    int curCourse = courseOrder.front();
    order.push_back(curCourse);
    courseOrder.pop();

    for (auto nextCourses : preqMap[curCourse])
    {
      courseDegrees[nextCourses]--;
      if (!courseDegrees[nextCourses])
        courseOrder.push(nextCourses);
    }
  }

  // case --> Still Exist Cycle
  if (order.size() == numCourses)
    return order;
  return {};
}
};