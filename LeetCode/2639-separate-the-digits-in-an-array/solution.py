class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        a = []
        for i in nums:
            for j in str(i):
                a.append(int(j))
        return a
