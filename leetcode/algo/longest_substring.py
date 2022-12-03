# Given a string s, find the length of the longest substring without repeating characters.

# Sliding window technique 

# Example 1:

# Input: s = "abcabcbb"
# Output: 3
# Explanation: The answer is "abc", with the length of 3.
# Example 2:

# Input: s = "bbbbb"
# Output: 1
# Explanation: The answer is "b", with the length of 1.
# Example 3:

# Input: s = "pwwkew"
# Output: 3
# Explanation: The answer is "wke", with the length of 3.
# Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
# Example 4:

# Input: s = ""
# Output: 0
 

def notWorking(s):
    longest_length = 0
    traversed_char = []
    for x in s:
        if x in traversed_char:
            if len(traversed_char) > longest_length:
                longest_length =  len(traversed_char)
            traversed_char.clear()

        traversed_char.append(x)
    return max(len(traversed_char), longest_length)


def lengthOfLongestSubstring(self, s):
    n = 0
    visited_nodes = []
    for x in s:
        while x in visited_nodes:
            visited_nodes.pop(0)
        visited_nodes.append(x)
        n = max(n, len(visited_nodes))
    return n

print(lengthOfLongestSubstring("dvdf"))