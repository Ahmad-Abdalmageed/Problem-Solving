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
    bool isSubtree(TreeNode* root, TreeNode* subRoot);
    bool isSameTree(TreeNode* root, TreeNode* subRoot);
};

bool Solution::isSubtree(TreeNode* root, TreeNode* subRoot){
  if(!subRoot) return true;
  if(!root) return false;

  if(this->isSameTree(root, subRoot)) return true;
  return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
}

bool Solution::isSameTree(TreeNode* root, TreeNode* subRoot){
  if(!root && !subRoot) return true;
  if(root && subRoot && root->val == subRoot->val)
    return (isSameTree(root->left, subRoot->left) &&
            isSameTree(root->right, subRoot->right));
  return false;
}