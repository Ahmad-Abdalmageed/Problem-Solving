class Solution {
public:
    int characterReplacement(string s, int k) {
        // Frequency Count Hash
        std::vector<int> counts(26);
        int res = 0;
        
        // Using Sliding Window Technique
        int i = 0;
        int j = 0;
        
        // Keep track of the Most Frequent Character
        int cMaxCount = 0;
        
        while(j < s.size()){
            counts[s[j] - 'A']++;
            cMaxCount = std::max(cMaxCount, counts[s[j] - 'A']); // update most frequent character
            
            if(j - i + 1 - cMaxCount > k){
                // Shift the Window and Decrement the Count of the left most character
                counts[s[i] - 'A']--;
                i++;
            }
            res = std::max(res, j - i + 1);
            j++;
            
        }
        return res;
    }
};