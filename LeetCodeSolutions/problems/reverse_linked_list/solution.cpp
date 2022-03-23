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
    ListNode* reverseList(ListNode* head){
        // Base case when head == null
        if(head == nullptr) return nullptr;

        // Recursively reverse the nodes 
        ListNode* newHead = head;

        if(head->next != nullptr){
            // Parse to the end of the list and return the last node as the new head
            newHead = reverseList(head->next);
            // Make the last node point to the current node --- the node before
            head->next->next = head;
        }

        // turns the first node into a tail
        head->next = nullptr;

        return newHead;
    }

};