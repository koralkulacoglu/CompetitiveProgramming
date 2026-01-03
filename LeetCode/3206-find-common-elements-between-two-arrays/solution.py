class Solution:
    def findIntersectionValues(self, nums1: List[int], nums2: List[int]) -> List[int]:
        ans = [0, 0]
        for i in nums1:
            ans[0] += i in nums2
        for i in nums2:
            ans[1] += i in nums1
        return ans
