class Solution:
    def bestHand(self, ranks: List[int], suits: List[str]) -> str:
        if len(set(suits)) == 1:
            return 'Flush'
        for i in ranks:
            if ranks.count(i) >= 3:
                return 'Three of a Kind'
        for i in ranks:
            if ranks.count(i) >= 2:
                return 'Pair'
        return 'High Card'
