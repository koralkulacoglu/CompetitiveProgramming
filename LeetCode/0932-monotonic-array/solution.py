class Solution(object):
    def isMonotonic(self, a):
        return sum([a[i]<=a[i+1] for i in range(len(a)-1)])==len(a)-1 or sum([a[i]>=a[i+1] for i in range(len(a)-1)])==len(a)-1
