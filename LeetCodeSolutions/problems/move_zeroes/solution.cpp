class Solution {
public:
void moveZeroes(vector<int>& nums){
    int i = 0;
    int j = 0;

    // Loop the array using pointer j to find the zeros
    while(j < nums.size()){
        // If current postion holds a non-zero element, swap it with the last position i
        if(nums[j] != 0){
            // Swapping
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
        }
        j++;
    }
}

};