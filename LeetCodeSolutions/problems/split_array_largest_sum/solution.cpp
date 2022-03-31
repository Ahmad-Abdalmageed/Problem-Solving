class Solution {
public:
    int splitArray(std::vector<int>& nums, int m);
private:
    std::vector<int> arrNums;
    int groups;
    bool canSplit(int candidate);
};

int Solution::splitArray(std::vector<int>& nums, int m){
    // Store Input Information
    arrNums = std::vector<int>(nums);
    groups = m;


    // Binary Seach Approach we need to find the minimum most 
    // possible summation of the splitted groups
    // We define our maximum most summation to be the whole array sum
    // and the minimum most possible summation is the maximum element of the array
    int left = INT_MIN;
    int rght = 0 ;
    for(auto number: arrNums){
        rght += number;
        left = std::max(left, number);
    }
    int res = 0;
    
    while(left <= rght){
        int mid = left + ((rght - left)/2);

        if(canSplit(mid)){
            // If we can split the array into subarrays which has 
            // a maximum sum less than the mid then we update our 
            // parameters 
            rght = mid-1; 
            res = mid;
        } else {
            left = mid+1;
        }
    }

    return res;
}

bool Solution::canSplit(int candidate){
    int arrCount = 0;
    int curSum = 0;
    // Check if we can split the array into sub arrays 
    // whose maximum summation is smaller than the candidate result
    for(auto number: arrNums){
        curSum += number;
        if(curSum > candidate){
            curSum = number;
            arrCount += 1;
        }
    }

    return (arrCount+1) <= groups; 
}
