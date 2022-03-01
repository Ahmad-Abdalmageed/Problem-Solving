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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);

        ListNode* left = dummy;
        ListNode* right=head;

        // Shift the right pointer by n Spaces
        for(int i = 0; i <n; i++){
            right=right->next;
        }

        // Find the nth Node from the end
        while(right != nullptr){
            right=right->next;
            left=left->next;
        }

        // Delete Node
        left->next=left->next->next;

        return dummy->next;
    }

};