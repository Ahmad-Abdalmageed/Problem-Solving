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
  int deepestLeavesSum(TreeNode *root);

private:
  int maxDepth = INT_MIN;
  int maxDepthSum = 0;
  void dfs(TreeNode *curNode, int curDepth);
};



void Solution::dfs(TreeNode *curNode, int curDepth) {
  // Sent Node is Null -- Gaurd Clause
  if (!curNode)
    return;

  // Cur Node is a Leaf Node
  if (!curNode->left && !curNode->right) {
    
    // Sum if reached bottom depth
    if (curDepth == this->maxDepth) {
      this->maxDepthSum += curNode->val;
    }
    // CurDepth is the Deepest -- Reset the Sum 
    else if (curDepth > this->maxDepth) {
      this->maxDepth = curDepth;
      this->maxDepthSum = curNode->val;
    }
  }

  // Traverse the Tree
  this->dfs(curNode->left, curDepth + 1);
  this->dfs(curNode->right, curDepth + 1);
}

int Solution::deepestLeavesSum(TreeNode *root) {
  //  Call the DFS Traversing Algorithm
  this->dfs(root, 0);
  return this->maxDepthSum;
}