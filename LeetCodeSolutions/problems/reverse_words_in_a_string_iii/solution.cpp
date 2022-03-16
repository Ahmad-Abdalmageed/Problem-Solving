class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        int j = 0;

        while(j < s.size()){
            // Find the end of the first word
            while(j < s.size() && s[j] != ' ') j++;

            // Swap each word in place
            reverse(s.begin()+i, s.begin()+j);

            // Update pointers
            i = j+1;
            j = i;

        }
        return s;
    }
};