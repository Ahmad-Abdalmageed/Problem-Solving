class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k){
        // Store the Count of each row's Soldiers and row i idx
        std::vector<std::vector<int>> countSols;
        std::vector<int> res; 

        // Find the index of the first zero in each row 
        for(int row = 0; row < mat.size() ; row++){
            int left = 0;
            int rght = mat[row].size()-1;

            while(left <= rght){
                int mid = left + (rght - left)/2;
                if(mat[row][mid] == 0) rght = mid-1;
                else left = mid+1;
            }
            // here the Count of Soldiers is the left pointer
            countSols.push_back({left, row});
        }

        // Use Two pointers approach to return the Weakest
        // First we sort the array based on the number of soldiers 
        std::sort(countSols.begin(), countSols.end());
        cout << countSols.size() << endl;
        cout << mat.size() << endl;
        int left = 0;
        int rght = 1;
        int count = 0;
        
        while(count < k && rght < countSols.size()){
            // Move if the left is weaker
            if(countSols[rght][0] > countSols[left][0]){
                left++;
                rght++;
            } else if (countSols[rght][0] > countSols[left][0]){
                // Swap same Soldier count rows 
                cout << "SS" << countSols[rght][0] << "  " << countSols[left][0] << endl;
                std::swap(countSols[rght], countSols[left]);
            }
            count ++;        
        }
        
        for(int i = 0; i < k ; i++){
            res.push_back(countSols[i][1]);
        }

        return res;
    }
};