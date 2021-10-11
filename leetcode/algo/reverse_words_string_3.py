#  https://leetcode.com/problems/reverse-words-in-a-string-iii/

#  Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.


#  Example 1:

#  Input: s = "Let's take LeetCode contest"
#  Output: "s'teL ekat edoCteeL tsetnoc"


class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join([x[::-1] for x in s.split(" ")])
