class Solution:
    def cellsInRange(self, s: str) -> List[str]:
        ab = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        ans = []
        for i in range(ab.index(s[0]), ab.index(s[3])+1):
            for j in range(int(s[1]), int(s[4])+1):
                ans.append(str(ab[i]) + str(j))
        return ans
