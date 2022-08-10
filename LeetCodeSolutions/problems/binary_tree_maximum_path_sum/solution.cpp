/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        dfs(root, result);
        return result;
    }
    
private:
    int dfs(TreeNode* root, int &result) {
        // Return 0 if root is null
        if (root == nullptr) return 0;
        
        int left = std::max(dfs(root->left, result), 0);
        int right = std::max(dfs(root->right, result), 0);
        
        result = std::max(result, root->val + left + right);
        
        return root->val + std::max(left, right);
    }
};
