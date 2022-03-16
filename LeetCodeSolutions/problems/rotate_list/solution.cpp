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
    ListNode* rotateRight(ListNode* head, int k){
        // Case Empty list
        if(head == nullptr) return head;
        
        // count the linked list size to get to the 
        // desired node at size - k - 1
        int listSize = 1;
        ListNode* tail = head;

        while(tail->next!=nullptr){
            tail = tail->next;
            listSize++;
        }
        
        // Fix K for cases with k > list size
        k = k % listSize;

        // for multiples of the same size of the list we do nothing
        if(k==0) return head;
        
        ListNode* new_tail = head;
        ListNode* new_head = nullptr;

        // Move the new head ptr size - k - 1 steps 
        for(int steps = 0 ; steps < listSize-k-1; steps++){
            new_tail = new_tail->next;

        }

        // Make the tail of the list point to the head 
        tail->next = head;
        
        // Make tail points to null and save new head
        new_head = new_tail->next;
        new_tail->next = nullptr;

        return new_head;
    }


};