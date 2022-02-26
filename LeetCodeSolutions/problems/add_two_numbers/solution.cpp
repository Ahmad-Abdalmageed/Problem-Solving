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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int newVal, remainder=0;
        ListNode *head=new ListNode(0);
        ListNode *curPtr=head;
        while (l1 != nullptr || l2 != nullptr){
            cout<<"here"<<endl;
            int x = l1 ? l1->val:0;
            int y = l2 ? l2->val:0;
            newVal= x + y + remainder;
            
            


            curPtr->next = new ListNode(newVal % 10);
            remainder=newVal/10;
  
cout << x << endl;

            cout << y << endl;

            cout<< "val: " << newVal<<endl;

            cout << "rem : " << remainder<<endl;


            
            curPtr = curPtr->next;

            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
        }
        if (remainder > 0){
            curPtr->next=new ListNode(remainder);
        }
        
        return head->next;


    }
};