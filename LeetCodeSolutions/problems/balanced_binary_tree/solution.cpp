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
// LEETCODE: 110. Balanced Binary Tree

    typedef std::pair<bool, int> BalanceHight;

    BalanceHight isBalancedDFS(TreeNode *root)
    {
      // Base Case :: Child Node
      if (root == nullptr)
        return BalanceHight{true, 0};

      BalanceHight left = isBalancedDFS(root->left);
      BalanceHight right = isBalancedDFS(root->right);

      bool isBalanced_ = (left.first && right.first && std::abs(left.second - right.second) <= 1);
      return BalanceHight{isBalanced_, 1 + std::max(left.second, right.second)};
    }

    bool isBalanced(TreeNode *root)
    {
      return isBalancedDFS(root).first;
    }
};