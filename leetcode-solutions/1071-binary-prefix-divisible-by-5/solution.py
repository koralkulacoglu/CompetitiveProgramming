class Solution:
    def prefixesDivBy5(self, nums: List[int]) -> List[bool]:
        res = []
        num = 0
        for i in nums:
            num = (num << 1) + i
            res.append(num%5 == 0)
        return res
