/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
// LEETCODE: 25. Reverse Nodes in k-Group
ListNode *getKthNode(ListNode *currentNode, int k)
{
  ListNode *kthNode = currentNode;
  while (kthNode != nullptr && k > 0)
  {
    kthNode = kthNode->next;
    k--;
  }
  return kthNode;
}
ListNode *reverseKGroup(ListNode *head, int k)
{
  ListNode *dummy = new ListNode(0, head);
  ListNode *groupPrev = dummy;

  while (true)
  {
    ListNode *kthNode = getKthNode(groupPrev, k);
    if (kthNode == nullptr)
      break;
    ListNode *groupNext = kthNode->next;

    ListNode *prev = kthNode->next;
    ListNode *current = groupPrev->next;
    ListNode *temp = nullptr;

    while (current != groupNext)
    {
      temp = current->next;
      current->next = prev;
      prev = current;
      current = temp;
    }

    temp = groupPrev->next;
    groupPrev->next = kthNode;
    groupPrev = temp;
  }
  return dummy->next;
}
};