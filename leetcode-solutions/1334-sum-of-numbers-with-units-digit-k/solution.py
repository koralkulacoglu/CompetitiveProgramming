class Solution:
    def minimumNumbers(self, num: int, k: int) -> int:
        if num == 0:
            return 0
        if k == 0:
            return -1 if str(num)[-1] != str(0) else 1
        ans = 1
        while num > 0:
            if str(num)[-1] == str(k):
                return ans
            num -= k
            ans += 1
        return -1

