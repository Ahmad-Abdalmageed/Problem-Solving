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
// LEETCODE: 100. Same Tree --- 0ms solution
    bool isSameTree(TreeNode* root, TreeNode* subRoot){
      if(!root && !subRoot) return true;
      if(root && subRoot && root->val == subRoot->val)
        return (isSameTree(root->left, subRoot->left) &&
                isSameTree(root->right, subRoot->right));
      return false;
    }
};

// // LEETCODE: 100. Same Tree
// bool isSameTree(TreeNode *p, TreeNode *q)
// {
//   // Base Case Child Nodes both nulls
//   if (p == nullptr && q == nullptr)
//     return true;

//   //  any of childs doesnot exist
//   if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr))
//     return false;
  
//   // values are not the same
//   if (p->val != q->val)
//     return false;

//   // Both Branches must be the same
//   return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
// }