class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target){
        // Divide into Two Problems and solve with two pointers approach
        std::sort(arr.begin(), arr.end());
        int mod = 1000000007;
        std::vector<long> count(101, 0);
        long ctr = 0;
        for(auto i: arr)count[i]++;

        for(int i = 0; i <= 100; i++){
            for(int j = i; j <= 100; j++){
                int k = target - i - j;
                if(k < 0 || k >100) continue;
                if(i==j && j==k) ctr += (count[i]*(count[i]-1)*(count[i]-2))/6;
                else if(i==j && j!=k) ctr += ((count[i]*(count[i]-1))/2)*count[k];
                else if(i <j && j < k) ctr += count[i] * count[j] *count[k];
            }
        }
        return (int)(ctr%mod);
    }


};