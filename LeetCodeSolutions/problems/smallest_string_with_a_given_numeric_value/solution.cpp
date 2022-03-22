class Solution {
public:
    string getSmallestString(int n, int k) {
        std::string alpha = "_bcdefghijklmnopqrstuvwxy_";

        // Remove n spaces from the result to be replaced by a's
        k -= n;

        // intialize the resulting string with as many z's as it can take
        std::string res((k/25), 'z');

        // If k is still larger than 25 fill with any alphabet with that number
        if(k % 25) res = alpha[k%25] + res;

        // add as many a's to the prefix of the result
        return std::string(n-res.size(), 'a') + res;
    }

};