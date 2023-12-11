class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        return max(arr,key=arr.count)
