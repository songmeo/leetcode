class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = ''.join(filter(str.isalpha, s))

