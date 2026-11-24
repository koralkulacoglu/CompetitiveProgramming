class Solution:
    def maxLength(self, nums: List[int]) -> int:
        ans = 0
        for i in [nums[i:j] for i in range(len(nums)) for j in range(i + 1, len(nums) + 1)]:
            if math.prod(i) == math.lcm(*i) * math.gcd(*i):
                ans = max(ans, len(i))
        return ans
