class Solution {
public:
    std::vector<std::vector<int>> combine(int n, int k);
private:
    int end;
    void backtrack(int start, std::vector<int>& comb);
    int combSize;
    std::vector<std::vector<int>> res;
};

// LEETCODE : Permutations --- Algorithms I
void Solution::backtrack(int start, std::vector<int>& comb){
    // Base Case
    if(comb.size() == combSize){
        // Copy the Current Combination array and pass it to the result array
        res.push_back(std::vector<int>(comb));
        return;
    }

    for(int i = start; i <= end; i++){
        comb.push_back(i);
        backtrack(i+1, comb);
        comb.pop_back();
    }
}

std::vector<std::vector<int>> Solution::combine(int n, int k){
    // Calculate the Permutation Formula
    end = n;
    combSize = k;

    // Start the recursive backtracking solution
    std::vector<int> comb;
    backtrack(1, comb);
    return res;
}