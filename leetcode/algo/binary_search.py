
# https://leetcode.com/problems/binary-search/

# Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

# You must write an algorithm with O(log n) runtime complexity.

 

# Example 1:

# Input: nums = [-1,0,3,5,9,12], target = 9
# Output: 4
# Explanation: 9 exists in nums and its index is 4



class Solution:
    def search(self, nums: List[int], target: int) -> int:
        start = 0
        end = len(nums)
        
        while (start != end):
            mid = (start + end)//2
            if nums[mid] == target:
                return mid
            
            if start == mid or end == mid:
                return -1
            
            if nums[mid] < target:
                start = mid
            elif nums[mid] > target:
                end = mid
        
        return -1
