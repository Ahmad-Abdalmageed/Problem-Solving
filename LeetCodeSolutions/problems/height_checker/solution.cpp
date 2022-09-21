class Solution {
public:
    // Brute Force Solution 
    // Sort & iterate two arrays and count differences
    int heightChecker(vector<int>& heights)
    {
        vector<int> expected(heights.begin(), heights.end());
        std::sort(expected.begin(), expected.end());
        
        int n = heights.size();
        int res = 0;
        
        
        for(int height = 0; height < n; height++)
        {
            if(heights[height] != expected[height])
                res++;
        }
        
        return res;
    }
};




