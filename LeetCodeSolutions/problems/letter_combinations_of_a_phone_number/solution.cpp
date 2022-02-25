class Solution{
    public:
        void backtrack(int curI, string curStr){
            if(curStr.size() == input.size()){
                cout << curStr << endl;
                res.push_back(curStr);
                return;
            }
            for(auto c : phone[input[curI]]){
                backtrack(curI+1, curStr + c);
            }
        }

        vector<string> letterCombinations(string digits) {
            input = digits;
            if(digits != ""){
                backtrack(0, "");
            }
            return res;
        }
    private:
        string input;
        vector<string> res = {};
        map<char, string> phone = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

};
