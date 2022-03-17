class Solution {
public:
    int scoreOfParentheses(string s){
        stack<char> sequence;
        int score = 0;
        int balance = 0;
        char lstP ;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                balance++;
            } else {
                balance--;
                if(s[i-1] == '(') score+= 1 << balance;
            }
        }
        return score;
    }
};