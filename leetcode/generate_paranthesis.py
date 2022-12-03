# https://leetcode.com/problems/generate-parentheses/

# Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.


# Example 1:

# Input: n = 3
# Output: ["((()))","(()())","(())()","()(())","()()()"]
# Example 2:

# Input: n = 1
# Output: ["()"]

class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        br = []
        for x in range(n):
            temp = []
            if not br:
                temp = ["()"]
            for x in br:
                temp.extend([
                    "("+x+")",
                    x+"()",
                    "()"+x
                ])

            br = list(set(temp))
        return br


print(Solution().generateParenthesis(2))
# ["(()())()","()(()())","(()(()))","()()()()","(()()())","(())()()","()((()))","((()()))","((()))()","()(())()","()()(())","(((())))","((())())"]
# ["(())(())","(())()()","()((()))","()(()())"]