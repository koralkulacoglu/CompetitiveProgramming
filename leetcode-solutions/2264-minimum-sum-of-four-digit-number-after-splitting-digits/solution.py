class Solution:
    def minimumSum(self, num: int) -> int:
        s = str(num)
        vals = ''.join(sorted(s))
        return min(int(vals[0]+vals[2]) + int(vals[1]+vals[3]), int(vals[1]+vals[2]) + int(vals[0]+vals[3]))
