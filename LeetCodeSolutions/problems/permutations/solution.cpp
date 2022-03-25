class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums);
private:
    void backtrack(int begin);
    std::vector<int> permutation;
    std::vector<std::vector<int>> result;
};

std::vector<std::vector<int>> Solution::permute(std::vector<int>& nums){
    // Store information
    permutation = std::vector<int>(nums);

    // Call the Backtracking Solution
    backtrack(0);
    return result;
}

void Solution::backtrack(int begin){
    // Base Case
    if(begin >= permutation.size()){
        result.push_back(permutation);
        return;
    }

    // Each loop we swap the first element with each other element 
    // and each recursive call swap the swapped elements with their 
    // next element untill begin reaches the end 
    for(int i = begin; i < permutation.size();i++){
        std::swap(permutation[begin], permutation[i]);
        backtrack(begin+1);

        // The Backtracking part where we reset the array in order to begin the next loop
        // and preserve the First Element in its place
        std::swap(permutation[begin], permutation[i]);
    }
}
