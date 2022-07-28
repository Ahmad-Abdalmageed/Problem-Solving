/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    // LEETCODE 138. Copy List with Random Pointer
    // ####### Using Hash Map #######
    Node *copyRandomList(Node *head)
    {
      std::unordered_map<Node *, Node *> originalToCopyMap;
      Node *ptrHead = head;

      while (ptrHead != nullptr)
      {
        originalToCopyMap[ptrHead] = new Node(ptrHead->val);
        ptrHead = ptrHead->next;
      }

      ptrHead = head;
      // Connect the Nodes
      while (ptrHead != nullptr)
      {
        // Connect Next Nodes
        originalToCopyMap[ptrHead]->next = originalToCopyMap[ptrHead->next];

        // Connect Random Nodes
        originalToCopyMap[ptrHead]->random = originalToCopyMap[ptrHead->random];

        ptrHead = ptrHead->next;
      }
      return originalToCopyMap[head];
    }

};