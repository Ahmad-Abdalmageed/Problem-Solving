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
    vector<vector<int>> levelOrderNodes;
    
    void levelOrderDFS(TreeNode* node, int depth)
    {
        // Return at the End of the Branch
        if(node == nullptr) return;
        
        // Add empty arrays to hold new depths values 
        if(levelOrderNodes.size() == depth) 
            levelOrderNodes.push_back({});
        
        levelOrderNodes[depth].push_back(node->val);
        levelOrderDFS(node->left, depth+1);
        levelOrderDFS(node->right, depth+1);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        levelOrderDFS(root, 0);
        return levelOrderNodes;
    }
};