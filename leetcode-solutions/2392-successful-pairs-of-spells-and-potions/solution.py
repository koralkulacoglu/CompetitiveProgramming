class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        potions.sort()
        res = []
        for spell in spells:
            idx = bisect.bisect_left(potions, (success + spell - 1)//spell)
            res.append(len(potions) - idx)
        return res


