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
    bool isValidBST(TreeNode* root){
        TreeNode* prev = nullptr;
        return validate(root, prev);
    }
    
    bool validate(TreeNode* node, TreeNode* &prev){
        // End of Tree return true
        if (node == nullptr) return true;
        
        // Inorder Traversal of tree till last child
        if(!validate(node->left, prev)) return false;
            
        if(prev != nullptr && prev->val >= node->val) return false;
        
        prev = node;
        
        if(!validate(node->right, prev)) return false;
        
        return true;
    }
};