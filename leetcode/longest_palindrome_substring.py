class Solution:
    def longestPalindrome(self, s: str) -> str:
        max_length = 0
        max_palin = ""
        
        if len(s) < 2:
            return s
        
        if s == s[::-1]:
            return s

        for x in range(len(s) - 1):
            for y in range(x+1, len(s) ):
                val = s[x:y+1]
                if val == val[::-1] and max_length < len(val):
                    max_length = len(val)
                    max_palin = val
        return s[0] if max_palin == "" else max_palin

        



print(Solution().longestPalindrome("abcdef"))

