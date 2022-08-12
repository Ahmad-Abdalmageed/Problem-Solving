// This is an excellent approach to this problem.
// My understanding:

// First count the number of occurrences of each element.
// Let the max frequency seen be M for element E
// We can schedule the first M-1 occurrences of E, each E will be followed by at least N CPU cycles in between successive schedules of E
// Total CPU cycles after scheduling M-1 occurrences of E = (M-1) * (N + 1) // 1 comes for the CPU cycle for E itself
// Now schedule the final round of tasks. We will need at least 1 CPU cycle of the last occurrence of E. If there are multiple tasks with frequency M, they will all need 1 more cycle.
// Run through the frequency dictionary and for every element which has frequency == M, add 1 cycle to result.
// If we have more number of tasks than the max slots we need as computed above we will return the length of the tasks array as we need at least those many CPU cycles.

class Solution {
public:
// LEETCODE: 621. Task Scheduler
int leastInterval(vector<char> &tasks, int n)
{
  std::unordered_map<char, int> tasksCount;
  int maxFreq = 0;
  for (auto const &task : tasks)
  {
    tasksCount[task] += 1;
    maxFreq = std::max(maxFreq, tasksCount[task]);
  }

  int time = (maxFreq - 1) * (n + 1);
  for (auto const &taskCount : tasksCount)
  {
    if (taskCount.second == maxFreq)
    {
      time++;
    }
  }

  return std::max(time, (int)tasks.size());
}
};


// HEAP APPROACH

// int leastInterval(vector<char> &arr, int n)
// {
//     // another approach is to use the heap for this process
//     // we will go till a length of n in every iteration in our process
//     // we will take the help of map for storing the count of every element
//     unordered_map<char, int> mp;
//     int ans = 0;
//     for (int it : arr)
//         mp[it]++;
//     priority_queue<int> mx;
//     for (auto it : mp)
//         mx.push(it.second);
    
//     // we will work on our heap, where every element will be used after a span of n 
    
//     while (!mx.empty())
//     {
//         vector<int> temp;
//         for (int i = 0; i <= n; i++)
//         {
//             if (!mx.empty())
//             {
//                 temp.push_back(mx.top());
//                 mx.pop();
//             }
//         }
//         for (int it : temp)
//         {
//             if (--it > 0)
//                 mx.push(it);
//         }
//         ans += (mx.empty() ? temp.size() : n + 1);
//     }
//     return ans;
// }




