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
// LEETCODE: 199. Binary Tree Right Side View
vector<int> rightSideView(TreeNode *root)
{
  if (root == nullptr)
    return {};

  std::vector<int> results;
  std::queue<TreeNode *> nodesQueue;
  nodesQueue.push(root);

  while (!nodesQueue.empty())
  {
    int nodesQueueSize = nodesQueue.size();

    for (int level = nodesQueueSize; level > 0; level--)
    {
      TreeNode *node = nodesQueue.front();
      nodesQueue.pop();

      if (level == nodesQueueSize)
        results.push_back(node->val);

      if (node->right != nullptr)
        nodesQueue.push(node->right);
      if (node->left != nullptr)
        nodesQueue.push(node->left);
    }
  }
  return results;
}
};