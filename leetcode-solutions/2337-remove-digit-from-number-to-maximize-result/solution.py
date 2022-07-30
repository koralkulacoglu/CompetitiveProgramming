class Solution:
    def removeDigit(self, number: str, digit: str) -> str:
        idx = []
        for i in range(len(number)):
            if number[i] == digit:
                idx.append(i)
        num = -1
        for i in idx:
            cur = number[:i] + number[i+1:]
            num = max(num, int(cur))
        return str(num)
