class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        bool found = false ;

        // Case where target is out of bounds 
        if(target > matrix[matrix.size()-1][matrix[0].size()-1]) return found;
        if(target < matrix[0][0]) return found;

        // Binary search each row for the target
        for(auto row: matrix){
            int i = 0;
            int j = row.size()-1;
            
            // Target does not exit in this row 
            if(target > row[j]) continue;
            
            while(!found && i <= j){                
                // if Target exists in this row search this row
                int mid = i + (j - i) / 2;  
                
                
                cout << mid << endl;
                cout << i << endl;
                cout << j << endl;
                
                if(target < row[mid]) j = mid-1;

                else if(target > row[mid]) i = mid+1;
                
                else found = true;
            }
        }

        return found;
    }

};