class Solution:
    def isVowel(self, c):
        if c == 'a': return True
        if c == 'e': return True
        if c == 'i': return True
        if c == 'o': return True
        if c == 'u': return True
        return False
        
    def reverseWords(self, s: str) -> str:
        s = s.split(' ')

        vowels = 0
        for c in s[0]:
            vowels += self.isVowel(c)

        res = [s[0]]
        for word in s[1:]:
            vowelCount = 0
            for c in word:
                vowelCount += self.isVowel(c)

            if vowelCount == vowels:
                res.append(word[::-1])
            else:
                res.append(word)

        return ' '.join(res)
