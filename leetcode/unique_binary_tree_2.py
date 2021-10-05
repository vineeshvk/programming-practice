# https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/636/week-1-september-1st-september-7th/3961/
# passed all test cases


# Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

# Example 1:


# Input: n = 3
# Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
# Example 2:

# Input: n = 1
# Output: [[1]]

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def __str__(self): return f"{self.val}, {self.left}, {self.right}"


class Solution:
    def generateTrees(self, n: int):
        return self.dfs_recursion(list(range(1, n+1)))

    def dfs_recursion(self, arr):
        nodes = []

        if not arr:
            return nodes

        for i in range(len(arr)):
            left = self.dfs_recursion(arr[:i])
            right = self.dfs_recursion(arr[i+1:])

            if not (left or right):
                nodes.append(TreeNode(arr[i]))

            elif left and right:
                for l in left:
                    for r in right:
                        nodes.append(TreeNode(arr[i], l, r))
            else:
                nodes.extend([TreeNode(arr[i], l) for l in left])
                nodes.extend([TreeNode(arr[i], None, r) for r in right])

        return nodes


val = Solution().generateTrees(3)
for i in val:
    print(i)
