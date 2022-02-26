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
        ListNode* head = new ListNode();
        ListNode* curPtr= head;
        while(list1 != nullptr && list2 != nullptr){
            
            int curVal;
            if(list1->val <=list2->val){
                curVal=list1->val;
                list1=list1->next;

            }else {
                curVal=list2->val;
                list2=list2->next;
            }
            curPtr->next= new ListNode(curVal);
            curPtr=curPtr->next;


      }
        if(list1 == nullptr){

            while(list2 != nullptr){

                curPtr->next=new ListNode(list2->val);

                list2=list2->next;

                

                curPtr=curPtr->next;

            }

        }
        if(list2 == nullptr){

            while(list1 != nullptr){

                curPtr->next=new ListNode(list1->val);

                list1=list1->next;

                

                curPtr=curPtr->next;

            }

        }
        return head->next;

        
    }
};