class Solution {
public:
bool isValid(string s){
    // Loop each element in string 
    // if oppenning Parentheses add one to VALIDATION
    // if clossing Parentheses minus one to VALIDATION
    // return true only if VALID is equal to zero
    stack<char> ORDER;
    for(auto p: s){
        switch (p)
        {
            case '{': ORDER.push('}'); break;
            case '(': ORDER.push(')'); break;
            case '[': ORDER.push(']'); break;
            default:
                if(ORDER.empty() || p != ORDER.top()) return false;
                else ORDER.pop();
        }
    }
    return ORDER.empty();
}

};