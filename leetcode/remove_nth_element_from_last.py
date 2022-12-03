# https://leetcode.com/problems/remove-nth-node-from-end-of-list/
# Given the head of a linked list, remove the nth node from the end of the list and return its head.


# Example 1:


# Input: head = [1,2,3,4,5], n = 2
# Output: [1,2,3,5]
# Example 2:

# Input: head = [1], n = 1
# Output: []
# Example 3:

# Input: head = [1,2], n = 1
# Output: [1]


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        simple_list = self.convertToList(head)
        target = simple_list[n - 1]
        prev_v, next_v = None, None

        if n - 2 >= 0:
            next_v = simple_list[n - 2]

        if n < len(simple_list):
            prev_v = simple_list[n]

        if prev_v:
            prev_v.next = next_v
        else:
            head = next_v

        target.next = None

        return head

    def convertToList(self, list):
        simple_list = []
        root = list
        while root:
            simple_list.append(root)
            root = root.next
        return simple_list[::-1]
