class Solution:
    def reverse(self, x: int) -> int:
        x = int(str(x)[::-1]) if '-' not in str(x) else int(str(x)[1:][::-1])*-1 
        x = 0 if not(-2147483648 < x < 2147483647) else x
        return x
        
