# https://leetcode.com/problems/merge-two-sorted-lists/
# You are given the heads of two sorted linked lists list1 and list2.

# Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

# Return the head of the merged linked list.


class Solution:
    def mergeTwoLists(self, list1, list2):
        root = None

        if not list1 and not list2:
            return list1 or list2

        if list1.val < list2.val:
            root = list1
            list1 = list1.next
        else:
            root = list2
            list2 = list2.next

        root.next = self.mergeTwoList(list1, list2)
        return root
