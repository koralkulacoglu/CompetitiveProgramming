class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        res = []
        for num in nums:
            s = str(num)
            for i in s:
                res.append(int(i))
        return res
