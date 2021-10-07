# https://leetcode.com/problems/squares-of-a-sorted-array/


# Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 

# Example 1:

# Input: nums = [-4,-1,0,3,10]
# Output: [0,1,9,16,100]
# Explanation: After squaring, the array becomes [16,1,0,9,100].
# After sorting, it becomes [0,1,9,16,100].
# Example 2:

# Input: nums = [-7,-3,2,3,11]
# Output: [4,9,9,49,121]


class Solution:
    def sortedSquares(self, nums: list[int]) -> list[int]:
        start = 0
        end = len(nums) - 1
        
        final_list = []
        
        while start < end:
            if abs(nums[start]) > abs(nums[end]):
                final_list.append(nums[start]**2)
                start += 1
            else:
                final_list.append(nums[end]**2)
                end -= 1
        final_list.append(nums[start]**2)
        return reversed(final_list)