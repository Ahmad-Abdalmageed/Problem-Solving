class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) 
    {
        int mxNum = -1;
        for(int num = arr.size() - 1; num >= 0; num--)
        {
            int temp = arr[num];
            arr[num] = mxNum;
            mxNum = std::max(temp, mxNum);
        }
        
        return arr;
    }
};