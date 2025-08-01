class Solution:
    MOD = int(1e9 + 7)

    def numberOfWays(self, startPos: int, endPos: int, k: int) -> int:
        @lru_cache(maxsize=None)
        def dp(pos, steps_left):
            if steps_left == 0:
                return int(pos == endPos)
            return (dp(pos - 1, steps_left - 1) + dp(pos + 1, steps_left - 1)) % self.MOD

        return dp(startPos, k)

