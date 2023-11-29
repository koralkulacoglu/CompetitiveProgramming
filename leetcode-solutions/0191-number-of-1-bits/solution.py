class Solution(object):
    def hammingWeight(self, n):
        return '{0:b}'.format(n).count('1')
