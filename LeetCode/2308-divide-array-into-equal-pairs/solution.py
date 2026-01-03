class Solution:
    def divideArray(self, nums: List[int]) -> bool:
        sNums = set(nums)
        for i in sNums:
            if nums.count(i)%2:
                return False
        return True
