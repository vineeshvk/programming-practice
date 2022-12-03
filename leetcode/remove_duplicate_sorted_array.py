class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        last = None
        for x in range(len(nums) - 1):
            if nums[x] == last: