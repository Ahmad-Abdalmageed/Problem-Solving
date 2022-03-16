class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target){
        int left = 0;
        int rght = numbers.size()-1;
        vector<int> res;

        while(left < rght){
            if(numbers[left] + numbers[rght] < target) left++;
            else if(numbers[left] + numbers[rght] > target) rght--;
            else{
                res.push_back(left+1);
                res.push_back(rght+1);
                break;
            }

        }

        return res;
    }

};