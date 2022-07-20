class Solution {
public:
  // LEETCODE:875. Koko Eating Bananas
  int minEatingSpeed(vector<int> &piles, int h)
  {
    // Use binary search to identify the number of
    // bananas/hour
    // Smallest possible amount koko can eat
    int left = 1;

    // The maximum amount
    int rght = *(std::max_element(piles.begin(), piles.end()));
      
    int result = rght;

    // Binary Search
    while (left <= rght)
    {
      int bananasRate = left + (rght - left) / 2;

      double hours = 0;
      // Calculate how many hours it takes
      for (auto const &bananas : piles)
      {
        hours += std::ceil((double) bananas / bananasRate);
      }


      // Update only if bananasRage is less than h
      if (hours <= h)
      {
        result = std::min(result, bananasRate);
        rght = bananasRate - 1;
      }
      else
      {
        left = bananasRate + 1;
      }
    }
    return result;
  }
};