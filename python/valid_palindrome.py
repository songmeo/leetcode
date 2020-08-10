class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = ''.join(filter(str.isalnum, s))
        if s == '':
            return True
        start, end = 0, len(s) - 1
        while start <= end:
            if s[start].lower() != s[end].lower():
                return False
            start = start + 1
            end = end - 1
        return True

class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = ''.join(filter(str.isalnum,s))
        while s:
            if s[0].lower() == s[-1].lower():
                s = s[1:-1]
            else:
                return False
        return True
