class Solution:
    def clumsy(self, n: int) -> int:
        val = ''
        for i in range(n):
            val += str(n-i)
            if i == n-1:
                break
            if i%4 == 0:
                val += '*'
            if i%4 == 1:
                val += '//'
            if i%4 == 2:
                val += '+'
            if i%4 == 3:
                val += '-'
        return eval(val)
