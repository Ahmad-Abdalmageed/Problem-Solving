class Solution {
public:
    // LEETCODE : 986. Interval List Intersections --- ALGORITHMS II
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        // Find the Intersection between every interval
        // Two Pointers Approach 
        int i = 0, j = 0;
        std::vector<std::vector<int>> res ;

        while(i < firstList.size() && j < secondList.size()){
            // Find A[i] N B[j]
            int left = std::max(firstList[i][0], secondList[j][0]);
            int rght = std::min(firstList[i][1], secondList[j][1]);

            if(left <= rght){
                res.push_back({left, rght});
            }

            // Remove the Interval with smallest endpoint
            if(firstList[i][1] < secondList[j][1]) i++;
            else j++;
        }
        return res;
    }

};