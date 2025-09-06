class Solution:
    def symmetric(self, n):
        return sum(int(i) for i in str(n)[:len(str(n))//2]) == sum(int(i) for i in str(n)[len(str(n))//2:]) if len(str(n)) % 2 == 0 else False

    def countSymmetricIntegers(self, low: int, high: int) -> int:
        return sum([self.symmetric(i) for i in range(low, high+1)])

