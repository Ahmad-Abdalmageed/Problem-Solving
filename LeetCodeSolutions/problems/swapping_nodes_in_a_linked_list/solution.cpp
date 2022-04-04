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
    ListNode* swapNodes(ListNode* head, int k){
        ListNode* dummy = new ListNode(0, head);
        ListNode* preLeft = dummy;
        ListNode* preRght = dummy;
        ListNode* left = head;
        ListNode* rght = head;

        for(int ctr = 0; ctr < k-1; ctr++){
            preLeft = left;
            left = left->next;
        }

        ListNode* curNode = left;
        while(curNode->next != nullptr){
            preRght = rght;
            rght = rght->next;
            curNode = curNode->next;
        }

        if(left == rght) return head;
        preRght->next = left;
        preLeft->next = rght;
        ListNode* temp = left->next;
        left->next = rght->next;
        rght->next = temp;
        return dummy->next;
    }

};