class Solution:
    def isPrefixString(self, s: str, words: List[str]) -> bool:
        for word in words:
            if len(s) == 0:
                return True
            if s.startswith(word):
                s = s[len(word):]
            else:
                return False
        return len(s) == 0
