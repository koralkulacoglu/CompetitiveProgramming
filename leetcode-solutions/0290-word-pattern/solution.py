class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        pattern = list(pattern.replace('"', ''))
        s = s.replace('"', '').split(' ')

        def indexes(ls, elem):
            indices = []
            for i in range(len(ls)):
               if ls[i] == elem:
                  indices.append(i)
            return indices
        
        if len(pattern) != len(s): return False
        
        for row in range(len(pattern)):
            if indexes(pattern, pattern[row]) != indexes(s, s[row]):
                return False
        return True
    

