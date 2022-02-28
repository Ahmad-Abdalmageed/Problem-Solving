class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res={};

        int i=0;
        if(nums.size()==0)return res;

        while(i<nums.size()){

            int start,end;

            start=nums[i];

            while(i+1<nums.size()&& nums[i+1]==nums[i]+1) i++;

            end=nums[i];

            if(start==end){

                res.push_back(to_string(start));

            } else{

                res.push_back(to_string(start)+"->"+to_string(end));

            }

            i++;

        }

        return res;



    }

};