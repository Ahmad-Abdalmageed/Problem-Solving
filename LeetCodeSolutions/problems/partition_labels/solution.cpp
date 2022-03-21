class Solution {
public:
    vector<int> partitionLabels(string s){
        vector<int> ans ;
        // Init a Vector of 26 letters that will hold the last appearence of each 
        // letter in the string 
        vector<int> last(26, 0);

        // Append the last appearence of each character
        for(int i = 0 ; i < s.size(); i++){
            last[s[i] - 'a'] = i;
        }

        // Calculate thge size of each partition
        int j = 0, anchor =0;
        for(int i=0; i < s.size(); i++){
            // j holds the last appearence of the first character in the parition
            j = max(j, last[s[i] - 'a']);

            if(i == j) {
                ans.push_back(i - anchor + 1);
                anchor = i + 1;
            }
        }
        return ans;
    }
};