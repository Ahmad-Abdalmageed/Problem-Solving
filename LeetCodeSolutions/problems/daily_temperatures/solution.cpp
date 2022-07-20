class Solution {
public:
  // LEETCODE: 739. Daily Temperatures
  vector<int> dailyTemperatures(vector<int> &temperatures)
  {
    // Using a Monotically decreasing stack
    std::stack<std::pair<int, int>> indexTemperatureStack;
    int tempArraySize = temperatures.size();
    std::vector<int> result(tempArraySize);

    for (int currentDay = 0; currentDay < tempArraySize; currentDay++)
    {
      int currentTemp = temperatures[currentDay];

      // found a greater temperature pop from stack and calculate difference
      while (!indexTemperatureStack.empty() && currentTemp > indexTemperatureStack.top().second)
      {
        // Extract lesser Temperature
        int tempDay = indexTemperatureStack.top().first;
        int temp = indexTemperatureStack.top().second;

        indexTemperatureStack.pop();

        // Days Difference
        result[tempDay] = currentDay - tempDay;
      }
        
      indexTemperatureStack.push({currentDay, currentTemp});
    }
    return result;
  }

};