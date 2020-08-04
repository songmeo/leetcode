class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        val = 0
        for c in word:
            if c.isupper():
                val = val + 1
        if val == 0 or val == len(word) or (val == 1 and word[0].isupper()):
            return True
        else:
            return False

if __name__ == '__main__':
	s = Solution()
	print(s.detectCapitalUse('Amazon'))
