class Solution {
public:
    // LEETCODE: Minimum Domino rotations
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms){
        // Select the First Domino, Since there must exit at least one 
        // value in the first domino common in all dominos , if none then there 
        // are no possible rotations available

        vector<int> targets = {tops[0], bottoms[0]};

        for(auto target : targets){
            int topMissing = 0;
            int bottomMissing = 0;
            
            for(int i = 0; i < tops.size(); i++){
                // If neither the top or the bottom have the target then skip
                if(tops[i] != target && bottoms[i] != target) break;

                // Calculate the missing spots of the target
                if(tops[i] != target) topMissing++;
                if(bottoms[i] != target) bottomMissing++;

                // Return the minimum missin spots for minimum rotations applicable
                if(i == tops.size()-1) return min(topMissing, bottomMissing);
            }
        }

        // If there exits no solution
        return -1;
    }
};