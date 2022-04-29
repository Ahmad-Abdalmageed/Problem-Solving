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
    // LEETCODE: 82. Remove Duplicates from Sorted List II --- ALGORITHM II
    ListNode* deleteDuplicates(ListNode* head){
        // Create a Dummy Node 
        ListNode* dummy = new ListNode(0, head);
        // initiate Two Pointers 
        ListNode* left = dummy;

        while(head != nullptr){
            
            if(head->next !=nullptr && head->val == head->next->val){
                // Move Both Pointers untill duplicate Found
                while(head->next != nullptr && head->next->val == head->val){
                    head = head->next;
                }
                left->next = head->next;
                
            } else {
                left = left->next;
            }

            head = head->next;
        }
        return dummy->next;
    }
};