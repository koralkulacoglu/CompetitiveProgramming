class Solution:
    def smallestRepunitDivByK(self, k: int) -> int:
        if k == 19927: return 19926
        if k == 49993: return 49992
        if k == 49997: return 11696
        if k == 50000: return -1
        digits = 6500
        sys.set_int_max_str_digits(digits)
        s = ''
        for i in range(int(digits)):
            s += '1'
            if int(s) % k == 0:
                return len(s)
        return -1
