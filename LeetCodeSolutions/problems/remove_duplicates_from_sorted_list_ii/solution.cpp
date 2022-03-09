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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* cur_node= head;
        ListNode* prv_node= dummy;
        
        while(cur_node!=nullptr){
            
            if(cur_node->next!=nullptr && (cur_node->val == cur_node->next->val)){
                while(cur_node->next!=nullptr && (cur_node->val == cur_node->next->val)){
                    cur_node=cur_node->next;
                }
                prv_node->next=cur_node->next;

            } else{
                prv_node=prv_node->next;
            }
            cur_node=cur_node->next;
        }
        return dummy->next;
        
    }
};