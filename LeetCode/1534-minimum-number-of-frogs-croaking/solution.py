from collections import Counter

class Solution:
    def minNumberOfFrogs(self, croakOfFrogs: str) -> int:
    
        stages = 'croak'
        count = Counter()
        max_frogs = 0

        for ch in croakOfFrogs:
            count[ch] += 1

            if count['c'] < count['r'] or count['r'] < count['o'] or count['o'] < count['a'] or count['a'] < count['k']:
                return -1

            active = count['c'] - count['k']
            max_frogs = max(max_frogs, active)

        if len(set(count[ch] for ch in stages)) != 1:
            return -1

        return max_frogs

