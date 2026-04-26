# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        #divide list into two halves using slow/fast pointers
        slow = head
        fast = head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        second_half = slow.next
        slow.next = None
        first_half = head

        cur1 = first_half
        cur2 = second_half

        #reverse the second half
        prev = None
        curr = second_half
        while curr:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt
        second_half = prev

        #merge two lists
        cur1 = head
        cur2 = second_half
        while cur2:
            nxt1 = cur1.next
            nxt2 = cur2.next
            cur1.next = cur2
            cur2.next = nxt1
            cur1 = nxt1
            cur2 = nxt2