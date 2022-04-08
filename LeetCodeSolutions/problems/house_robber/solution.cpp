class Solution {
public:
    int rob(vector<int>& nums){
        int house1 = 0, house2 = 0;

        // [house1 , house2, n, n+1, n+2, ......]
        for(int n: nums){
            int temp = std::max(n+house1, house2);
            house1 = house2;
            house2 = temp;
        }
        return house2;
    }   

};