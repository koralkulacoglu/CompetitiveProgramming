def calc(c, d, e, f):
    # print(f'{c}({d}+{e}){f}')
    if c == '':
        c = 1
    if f == '':
        f = 1
    return int(c)*(int(d)+int(e))*int(f)

class Solution:
    def minimizeResult(self, e: str) -> str:
        ans = 1e9
        res = e
        a, b = e.split('+')
        for i in range(len(a)):
            c, d = a[:i], a[i:]
            for j in range(1, len(b)+1):
                f, e = b[j:], b[:j]             
                cur = calc(c, d, e, f)
                if cur < ans:
                    ans = cur
                    res = f'{c}({d}+{e}){f}'
        return res
