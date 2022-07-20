class Solution {
public:
  // LEETCODE: 84. Largest Rectangle in Histogram
  int largestRectangleArea(vector<int> &heights)
  {
    int numberofSamples = heights.size();
    int maxArea = 0;
    std::stack<std::pair<int, int>> indexHeightStack;

    // Keep track of the Lowest heights in the Stack
    for(int currentPosition = 0; currentPosition < numberofSamples; currentPosition++){
      int startingPosition = currentPosition;

      // If curremt height is smaller than stack top
      // calculate the max area it can have and update stack 
      while(!indexHeightStack.empty() && indexHeightStack.top().second > heights[currentPosition]){
        int newPosition = indexHeightStack.top().first;
        int newHeight = indexHeightStack.top().second;
        indexHeightStack.pop();
        
        int newArea = newHeight * (currentPosition - newPosition);
        maxArea = std::max(maxArea, newArea);
        startingPosition = newPosition;
      }
      indexHeightStack.push({startingPosition, heights[currentPosition]});
    }
    // At the end stack may not be empty, some heights can still extend to end
    // calculate their max heights
    while(!indexHeightStack.empty()){
      int newWidth = heights.size() - indexHeightStack.top().first;
      int newheight = indexHeightStack.top().second;
      indexHeightStack.pop();

      maxArea = std::max(maxArea, newheight*newWidth);
    }

    return maxArea;
  }

};