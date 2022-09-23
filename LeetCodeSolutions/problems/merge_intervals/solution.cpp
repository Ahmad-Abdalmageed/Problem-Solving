class Solution {
public:
    
    /* Overlap cases:   Is ---Js-- Ie --- Je
       1 - I[1] >= J[0]
       2 - I[0] > J[0] && I[1] < j[1]
       
       We Can sort the intervals to get sorted interval beginnings
     */
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        std::sort(intervals.begin(), intervals.end());
        vector<vector<int>> res{intervals[0]};
        
        for(auto i: intervals)
        {
            if(i[0] <= res.back()[1])
            {
                res.back()[1] = std::max(i[1], res.back()[1]);
            } else {
                res.push_back(i);
            }
        }
        return res;
    }
};