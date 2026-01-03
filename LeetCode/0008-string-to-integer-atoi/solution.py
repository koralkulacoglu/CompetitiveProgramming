class Solution:
    def myAtoi(self, s: str) -> int:
        s=s.lstrip() 
        negative=False
        if not s:return 0
        if s[0]=="-":
            negative=True
            s=s[1:]
        elif s[0]=="+":
            negative=False
            s=s[1:]
        ans=0
        for i in s:
            if i not in '0123456789':
                break
            else:
                ans=ans*10+int(i)
        if negative:
            ans=-ans
        return max(min(ans,2**31 -1),-2**31)

