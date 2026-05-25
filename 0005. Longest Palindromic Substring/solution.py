class Solution:
    def longestPalindrome(self, s: str) -> str:
        if not s:
            return ""

        longest = s[0]
        for i in range(len(s)):
            for j in range(i + 1, len(s)):
                buf = s[i:j + 1]
                if self.is_palindrome(buf) and len(buf) > len(longest):
                    longest = buf

        return longest

    def is_palindrome(self, s: str) -> bool:
        return s == s[::-1]
