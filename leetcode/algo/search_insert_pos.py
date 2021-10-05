# https://leetcode.com/problems/search-insert-position/
# Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

# You must write an algorithm with O(log n) runtime complexity.

 

# Example 1:

# Input: nums = [1,3,5,6], target = 5
# Output: 2


class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        start = 0
        end = len(nums) - 1
        
        while start < end:
            mid = (start + end) // 2
            
            if nums[mid] == target:
                return mid
            
            if end - start == 1:
                if nums[start] > target:
                    return start
                if nums[end] < target:
                    return end+1
                return end
            
            if nums[mid] < target:
                start = mid
            else:
                end = mid
        return start if nums[start] >= target  else start + 1
        