class Solution {
public:
    std::vector<std::string> letterCasePermutation(std::string s);
private:
    std::string input;
    void dfs(int pos);
    std::vector<std::string> res;
};

void Solution::dfs(int pos){
    // Base Case 
    if(pos == input.size()){
        res.push_back(input);
        return;
    }
    dfs(pos+1);

    // Each time we have Two Options if it is a string 
    // we convert to uppercase and continue or lowercase
    if(isalpha(input[pos])){
        input[pos] = islower(input[pos]) ? toupper(input[pos]): tolower(input[pos]);
        dfs(pos+1);
    }
}

std::vector<std::string> Solution::letterCasePermutation(std::string s){
    // Store info
    input = std::string(s);

    // backtrack 
    dfs(0);
    return res;
}
