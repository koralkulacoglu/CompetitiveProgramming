class Solution:
    def largestInteger(self, num: int) -> int:
        num = [int(i) for i in list(str(num))]
        for i in range(len(num)):
            cur = num[i]
            best = num[i]
            idx = i
            for j in range(i, len(num)):
                if cur%2 == num[j]%2 and num[j] >= best:
                    best = num[j]
                    idx = j
            
            num[i], num[idx] = num[idx], num[i]
        
        num = int(''.join(map(str, num)))
        return num
