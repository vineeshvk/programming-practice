# https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/636/week-1-september-1st-september-7th/3960/
# passed all test cases


# You are given an integer array nums of length n where nums is a permutation of the numbers in the range [0, n - 1].

# You should build a set s[k] = {nums[k], nums[nums[k]], nums[nums[nums[k]]], ... } subjected to the following rule:

# The first element in s[k] starts with the selection of the element nums[k] of index = k.
# The next element in s[k] should be nums[nums[k]], and then nums[nums[nums[k]]], and so on.
# We stop adding right before a duplicate element occurs in s[k].
# Return the longest length of a set s[k].

 

# Example 1:

# Input: nums = [5,4,0,3,1,6,2]
# Output: 4
# Explanation: 
# nums[0] = 5, nums[1] = 4, nums[2] = 0, nums[3] = 3, nums[4] = 1, nums[5] = 6, nums[6] = 2.
# One of the longest sets s[k]:
# s[0] = {nums[0], nums[5], nums[6], nums[2]} = {5, 6, 2, 0}


class Solution:
    def arrayNesting(self, nums: list[int]) -> int:
        return self.dfs(nums)

    def dfs (self, nodes):
        traversedNodes = set()
        checkInNodes = set()
        final = []

        currentI = 0
        i = currentI
        while len(traversedNodes) < len(nodes) and i < len(nodes):
            if nodes[i] not in traversedNodes:
                i = nodes[i]
                traversedNodes.add(i)
                checkInNodes.add(i)
            else:
                final.append(len(checkInNodes))
                checkInNodes = set()
                currentI += 1
                i=currentI
        final.append(len(checkInNodes))


        return max(final)
