# https://leetcode.com/problems/valid-parentheses/
# Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

# An input string is valid if:

# Open brackets must be closed by the same type of brackets.
# Open brackets must be closed in the correct order.


# Example 1:

# Input: s = "()"
# Output: true

class Solution:
    def isValid(self, s: str) -> bool:
        brackets = {
            ")": "(",
            "}": "{",
            "]": "["
        }
        stack = []

        for x in s:
            value = brackets.get(x)
            if not value:
                stack.append(x)
            else:
                if not stack or value != stack.pop():
                    return False
        
        return not stack

print(Solution().isValid("(]"))