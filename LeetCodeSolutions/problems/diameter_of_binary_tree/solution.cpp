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
    int diameterOfBinaryTree(TreeNode* root)
    {
        int result = 0;
        dfs(root, result);
        return result;
    }
private:    
    int dfs(TreeNode* root, int& diameter)
    {
        if(root == nullptr) return 0;
        int left = dfs(root->left, diameter);
        int right = dfs(root->right, diameter);
        
        diameter = std::max(diameter, left+right);
        return 1 + max(left, right);
    }
    
};