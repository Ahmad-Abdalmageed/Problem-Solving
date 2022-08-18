/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
  // LEETCODE: 133. Clone Graph
  Node* cloneGraph(Node *node);

private:
  std::map<Node*, Node*> oldNewMap;
};

Node* Solution::cloneGraph(Node* node)
{
  if (node == nullptr)
  {
    return nullptr;
  }

  if (oldNewMap.find(node) == oldNewMap.end())
  {
    oldNewMap[node] = new Node(node->val, {});

    for (auto const &neighbor : node->neighbors)
    {
      oldNewMap[node]->neighbors.push_back(cloneGraph(neighbor));
    }
  }
  return oldNewMap[node];
}