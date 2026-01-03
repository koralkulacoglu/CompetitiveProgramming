class Solution:
    def minimumRightShifts(self, nums: List[int]) -> int:
        st = sorted(nums)
        idx = nums.index(min(nums))
        dist = idx
        
        if st == nums:
            return 0
        
        for i in range(len(nums)):
            if st[i] != nums[(i+dist)%len(nums)]:
                return -1

        return len(nums) - idx
