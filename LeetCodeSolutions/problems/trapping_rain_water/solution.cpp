class Solution {
public:
// LEETCODE: 42. Trapping Rain Water
int trap(vector<int> &height)
{
  //  Using Two Pointer Approach to Calculate the
  //  amount of water trapped at each position i
  int l = 0, r = height.size() - 1;
  int maxR = height[r], maxL = height[l];

  // Calculate the following eq :
  // res += Min(maxR, maxL) - Current Height
  int res = 0;

  //  Loop untill both pointers reach each other
  while (l < r)
  {
    // Update the Left pointer if it is the minimum one
    if (maxL < maxR)
    {
      l++;
      maxL = std::max(height[l], maxL);
      res += maxL - height[l];
    }
    else
    {
      r--;
      maxR = std::max(height[r], maxR);
      res += maxR - height[r];
    }
  }
  return res;
}

};