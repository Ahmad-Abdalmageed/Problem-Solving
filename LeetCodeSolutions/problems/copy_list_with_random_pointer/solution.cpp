/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // case no head
        if(head==nullptr) return nullptr;
        Node* list1 = head;
        Node* list2 = nullptr;
         
        // update current list with copies of each node
        while(list1 != nullptr){
            // create new node with list1 value and next node
            list2= new Node(list1->val);
            list2->next=list1->next;
            
            // update pointers 
            list1->next=list2;
            list1=list1->next->next;


        }
        // update rand pointers with copy nodes
        list1=head;
        

        while(list1!=nullptr){
            if(list1->random!=nullptr){


                list1->next->random= list1->random->next;
            }

            list1=list1->next->next;
        }
        
        // extract the new list from old list
        list1 = head;
        Node* list2_head= list1->next;
        
        while(list1 != nullptr){
            list2=list1->next;
            list1->next = list2->next;
            if(list2->next!=nullptr){
                list2->next = list2->next->next;
            }
            list1=list1->next;

        }
        return list2_head;
    }
};