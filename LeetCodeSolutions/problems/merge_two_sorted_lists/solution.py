# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        merged_list = ListNode()
        curr_head = merged_list

        while list1 and list2:
            if list1.val <= list2.val:
                curr_head.next = list1
                list1 = list1.next
            else:
                curr_head.next = list2
                list2 = list2.next
            curr_head = curr_head.next

        if list1: 
            curr_head.next = list1
        elif list2:
            curr_head.next = list2
        
        return merged_list.next



