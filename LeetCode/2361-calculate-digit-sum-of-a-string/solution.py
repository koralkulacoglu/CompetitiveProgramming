def chunks(lst, n):
    for i in range(0, len(lst), n):
        yield sum(lst[i:i + n])

class Solution:
    def digitSum(self, s: str, k: int) -> str:
        l = list(map(int, list(s)))
        while len(''.join(map(str, l))) > k:
            l = list(chunks(l, k))
            l = list(map(int, ''.join(map(str, l))))
        return ''.join(map(str, l))
