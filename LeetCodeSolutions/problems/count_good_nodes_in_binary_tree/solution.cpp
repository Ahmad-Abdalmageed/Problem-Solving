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
    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return goodNodesCount;
        
    }
    
    void dfs(TreeNode* node, int currMaxValue) {
        if(node == nullptr) return;
        
        if(node->val >= currMaxValue){
            goodNodesCount++;
        }
        
        currMaxValue = std::max(currMaxValue, node->val);
            
        dfs(node->left, currMaxValue);
        dfs(node->right, currMaxValue);
    }
        
private: 
    int goodNodesCount = 0;
};