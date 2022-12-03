# https://leetcode.com/problems/letter-combinations-of-a-phone-number/
# Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

# A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


# Example 1:

# Input: digits = "23"
# Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
# Example 2:

# Input: digits = ""
# Output: []
# Example 3:

# Input: digits = "2"
# Output: ["a","b","c"]

class Solution:
    def letterCombinations(self, digits: str) -> list[str]:
        phone = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz",
        }

        combined_list = set()
        for x in range(len(digits)):
            value = phone[digits[x]]
            if x == 0:
                combined_list = combined_list.union(set(value))
            else:
                combined_list = self.multiply_letters(combined_list, set(value))
        return list(combined_list)



    def multiply_letters(self, list1, list2):
        combined_list = set()

        for x in list1:
            for y in list2:
                combined_list.add(x+y)
        return combined_list

print(Solution().letterCombinations("23"))
