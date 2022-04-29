class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Sort the Input Array to skip duplicates
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        
        // Fix the first two numbers  
        // Search for the third number which equals to
        // z = -( x + y ) and append to the result
        
        for(int i = 0; i < nums.size(); i++){
            int lptr = i+1;
            int rptr = nums.size() - 1;
        
            // check for duplicate .. Exit loop and skip to the next 
            if( i > 0 && nums[i] == nums[i-1]){
                
                // Skip Duplicates 
                
            } else {
                
                while(lptr < rptr){
                    int summation = nums[i] + nums[lptr] + nums[rptr];                
                    
                    if(summation < 0){
                        lptr++;
                    }
                    else if(summation > 0){
                        rptr--;

                    }
                    else{
                        
                        res.push_back({nums[i], nums[rptr], nums[lptr]});
                        lptr++;
                        while(lptr < rptr && nums[lptr-1] == nums[lptr]){
                            lptr++;
                        }
                    }   
                }
            }
        }

        return res;
    }
};