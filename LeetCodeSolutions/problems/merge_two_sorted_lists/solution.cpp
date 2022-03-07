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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* CUR_HEAD1 = list1;
        ListNode* CUR_HEAD2 = list2;
        ListNode* NEW_LIST = new ListNode(0);
        ListNode* TRAV_LIST = NEW_LIST;

        while(CUR_HEAD1!=nullptr && CUR_HEAD2 != nullptr){
            if(CUR_HEAD1->val < CUR_HEAD2->val){
                TRAV_LIST->next = new ListNode(CUR_HEAD1->val);
                CUR_HEAD1 = CUR_HEAD1->next;
            } else {
                TRAV_LIST->next = new ListNode(CUR_HEAD2->val);
                CUR_HEAD2 = CUR_HEAD2->next;

            }
            TRAV_LIST = TRAV_LIST->next;
        }

        while(CUR_HEAD1!=nullptr){
            TRAV_LIST->next = new ListNode(CUR_HEAD1->val);
            CUR_HEAD1 = CUR_HEAD1->next;
            TRAV_LIST=TRAV_LIST->next;
        }
        while(CUR_HEAD2 != nullptr){
            TRAV_LIST->next = new ListNode(CUR_HEAD2->val);        
            CUR_HEAD2 = CUR_HEAD2->next;
            TRAV_LIST=TRAV_LIST->next;        
        }
        return NEW_LIST->next;   
    }
};