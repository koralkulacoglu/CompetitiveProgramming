class Solution:
    def countGoodNumbers(self, n: int) -> int:
        MOD = int(1e9+7)
        return pow(5, (n+1)//2, MOD) * pow(4, n//2, MOD) % MOD

