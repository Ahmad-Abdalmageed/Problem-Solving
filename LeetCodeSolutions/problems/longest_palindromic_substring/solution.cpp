class Solution {
public:
    string longestPalindrome(string s){
        int max = 0;
        string res;
        if(s.size() == 1){
            return s;
        }
        for(unsigned int i = 0; i < s.size() ; i++){

            // Odd Case .. Center Expansion
            int left = i;
            int right = i;

            while(left >= 0 && right < s.size()  &&  s[left] == s[right]){
                if((right - left + 1) > max){
                    max = right - left + 1;
                    res = s.substr(left, right - left + 1);
                }
                left--;
                right++;
            }

            // Even Case
            left = i;
            right = i+1;
            while(left >= 0 && right < s.size() && s[left] == s[right]){
                if((right - left + 1) > max ){
                    max = right - left + 1;
                    res = s.substr(left, right - left + 1);
                    cout << res << endl;

                }
                left--;
                right++;
            }
        }
        return res;
    }

};