class Solution
{
public:
  bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites);

private:
  std::unordered_map<int, std::vector<int>> _prequisites;
  std::vector<bool> _visited;

  bool dfs(int curCourse);
};


bool Solution::canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites)
{
  // Prepare Prequesites map
  for (int course = 0; course < numCourses; course++)
  {
    _prequisites[course] = {};
  }
  for (auto const &preq : prerequisites)
  {
    _prequisites[preq[0]].push_back(preq[1]);
  }

  _visited = std::vector<bool>(numCourses, false);

  for (int course = 0; course < numCourses; course++)
  {
    if (!dfs(course))
    {
      return false;
    }
  }
  return true;
}

bool Solution::dfs(int curCourse)
{
  // Cycle Detected
  if (_visited[curCourse])
    return false;

  // Already Finished Prerequisites
  if (_prequisites[curCourse].empty())
    return true;

  // Add to Visited Courses
  _visited[curCourse] = true;
  for (auto const &preq : _prequisites[curCourse])
  {
    // Break if One Course Cannot be Completed
    if (!dfs(preq))
      return false;
  }

  // Finished Current Course
  _visited[curCourse] = false;
  _prequisites[curCourse] = {};

  return true;
}