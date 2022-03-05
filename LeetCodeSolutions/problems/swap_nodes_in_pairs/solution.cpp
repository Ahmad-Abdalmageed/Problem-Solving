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
ListNode* swapPairs(ListNode* head){
    ListNode* NEW_LIST = new ListNode(0);
    
    if(head == nullptr) return head;

    NEW_LIST->next = head;
    ListNode* PRV_NODE = NEW_LIST;
    ListNode* CUR_NODE = PRV_NODE->next;

    while(CUR_NODE != nullptr && CUR_NODE->next != nullptr){
        // Swap both heads with consideration of the rest of the list 
        ListNode* list = CUR_NODE->next->next;  
        ListNode* temp = CUR_NODE->next;
        
        CUR_NODE->next = list;
        temp->next = CUR_NODE;
        PRV_NODE->next = temp;

        // Update Pointers
        PRV_NODE = CUR_NODE;
        CUR_NODE = list;
    }
    return NEW_LIST->next;
}

};