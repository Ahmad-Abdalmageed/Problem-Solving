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

// LEETCODE: 143. Reorder List
class Solution
{
public:
  void reorderList(ListNode *head);

private:
  ListNode *reverseList(ListNode *head);
  void mergeList(ListNode *head1, ListNode *head2);
};


// LEETCODE: 143. Reorder List
void Solution::reorderList(ListNode *head)
{
  if (head->next == nullptr)
    return;
  ListNode *ptrPrev;
  ListNode *ptrFast = head;
  ListNode *ptrSlow = head;

  while (ptrFast != nullptr && ptrFast->next != nullptr)
  {
    ptrPrev = ptrSlow;
    ptrSlow = ptrSlow->next;
    ptrFast = ptrFast->next->next;
  }

  // Divide the List into two portions
  ptrPrev->next = nullptr;

  ListNode *listFirstHalf = head;
  ListNode *listSecondHalf = reverseList(ptrSlow);

  mergeList(listFirstHalf, listSecondHalf);
}

ListNode *Solution::reverseList(ListNode *head)
{
  // return if Null
  if (head == nullptr)
    return head;

  ListNode *newHead = head;

  // Traverse to end of the List
  if (head->next != nullptr)
  {
    // Each time return the Current Reversed nodes
    newHead = reverseList(head->next);

    // Make previous head point to the current head
    head->next->next = head;
  }

  // Always end the current reversed nodes with a nullptr
  head->next = nullptr;
  return newHead;
}

void Solution::mergeList(ListNode *head1, ListNode *head2)
{
  while (head1 != nullptr)
  {
    // Save Remaining Parts of the Lists
    ListNode *ptrHead1 = head1->next;
    ListNode *ptrHead2 = head2->next;

    head1->next = head2;
    if(ptrHead1 == nullptr) break;
    head2->next = ptrHead1;

    head1 = ptrHead1;
    head2 = ptrHead2;
  }
}
