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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int curRoot = 0;
        return build(preorder, inorder, curRoot, 0, inorder.size()-1);
    }
private: 
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& curRoot, int leftSubTree, int rightSubTree){
        if(leftSubTree > rightSubTree) return nullptr;
        
        // Create Root Node
        TreeNode* root = new TreeNode(preorder[curRoot]);
        
        int rootFoundInorder = 0;
        
        // Find the Root index in the inOrder Vector
        for(int i = 0; i < inorder.size(); i++) {
            if ( inorder[i] == preorder[curRoot]) {
                rootFoundInorder = i;
                break;
            }
        }
        
        // Increment Current root to nexr position
        curRoot++;
        
        // Recurse to the left and right, Execlude the Root from found inorder and send 
        // left and right trees
        root->left = build(preorder, inorder, curRoot, leftSubTree, rootFoundInorder - 1);
        root->right = build(preorder, inorder, curRoot, rootFoundInorder + 1, rightSubTree);
        
        return root;
    }
};