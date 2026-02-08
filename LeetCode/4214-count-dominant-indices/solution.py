class Solution:
    def dominantIndices(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0
        for i in range(n-1):
            if nums[i] > sum(nums[i+1:]) / (n - i - 1):
                ans += 1
        return ans
