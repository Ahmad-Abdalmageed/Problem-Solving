/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root);
private:
    void dfs(Node* node, Node* next);
};

void Solution::dfs (Node* node, Node* next){
    // base case current node is null
    if(node==nullptr) return;

    node->next = next;

    // traverse to the left
    dfs(node->left, node->right);
    
    // traverse to the right with next pointer pointing to 
    // current node next if exist
    dfs(node->right, (node->next != nullptr) ? node->next->left: nullptr);
}

Node* Solution::connect(Node* root){
    dfs(root, nullptr);
    return root;
}