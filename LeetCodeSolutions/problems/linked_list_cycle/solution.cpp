/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* FAST_PTR = head;
        ListNode* SLOW_PTR = head;
        
        while(FAST_PTR && FAST_PTR->next){

            FAST_PTR = FAST_PTR->next->next;
            SLOW_PTR=SLOW_PTR->next;
            if(FAST_PTR == SLOW_PTR){

                return true;

            }
        }
        return false;
        
    }
};