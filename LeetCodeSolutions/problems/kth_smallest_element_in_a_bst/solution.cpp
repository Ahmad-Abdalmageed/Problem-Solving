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
    int kthSmallest(TreeNode* root, int k) {
        inOrder(root, k);
        return result;
    }
    
    void inOrder(TreeNode* root, int &k){
        // Return if null
        if(root == nullptr) return;
        
        // Check Left -> get to the Farthest left pointer
        inOrder(root->left, k);
        
        // Decrement the Counter 
        k--;
        
        if(k == 0) {
            result = root->val;
            return;
        }
        
        inOrder(root->right, k);
    }
private:
    int result;
};