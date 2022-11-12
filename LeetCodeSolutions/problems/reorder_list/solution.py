# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        # Divide the List in Half
        slow = head
        fast = head.next

        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        
        second = slow.next
        prev = None
        slow.next = None # Split Second from first

        while second:
            temp = second.next
            second.next = prev
            prev = second
            second = temp

        first = head
        second = prev

        while second:
            temp_first = first.next
            temp_second = second.next

            first.next = second
            second.next = temp_first

            first = temp_first
            second = temp_second
        


            



        

