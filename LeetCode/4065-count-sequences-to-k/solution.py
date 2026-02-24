from fractions import Fraction

class Solution:
    def countSequences(self, nums: List[int], k: int) -> int:
        dp = defaultdict(int)
        dp[Fraction(1)] = 1
        for num in nums:
            tempDp = defaultdict(int)
            for val in dp:
                freq = dp[val]
                tempDp[val * num] += dp[val]
                tempDp[val / num] += dp[val]

            for val in tempDp:
                freq = tempDp[val]
                dp[val] += freq

        return dp[k]

