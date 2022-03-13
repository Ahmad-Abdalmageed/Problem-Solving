class Solution {
public:
    bool isValid(string s) {
        stack<char> qParenthes;
        map<char, char> brackets={
            {'(', ')'},
            {'{', '}'},
            {'[', ']'}
        };
        
        for(auto p: s){
            // current char is an opening parentheses 
            if(brackets.find(p) != brackets.end()){
                qParenthes.push(p);
            } else {
                if(!qParenthes.empty() && brackets[qParenthes.top()] == p){
                  qParenthes.pop();  
                } else {
                    return false;
                }
            }
        }
        
        return qParenthes.empty();
    }
};