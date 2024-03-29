/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
// LEETCODE:235. Lowest Common Ancestor of a Binary Search Tree
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
  // Cases Solution
  if (p->val < root->val && q->val < root->val)
    return lowestCommonAncestor(root->left, p, q);
  else if (p->val > root->val && q->val > root->val)
    return lowestCommonAncestor(root->right, p, q);
  else
    return root;
}

};