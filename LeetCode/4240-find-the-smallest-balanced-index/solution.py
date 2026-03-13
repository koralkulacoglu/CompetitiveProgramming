class Solution:
    def smallestBalancedIndex(self, nums: list[int]) -> int:
        n = len(nums)
        
        psaL = [0 for i in range(n)]
        for i in range(1, n):
            psaL[i] = psaL[i-1] + nums[i-1]

        psaR = [1 for i in range(n)]
        for i in range(n-2, -1, -1):
            psaR[i] = min(int(1e18), psaR[i+1] * nums[i+1])

        for i in range(n):
            if psaL[i] == psaR[i]:
                return i

        return -1
