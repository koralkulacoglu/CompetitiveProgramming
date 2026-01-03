class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for a in range(len(nums)):
            if nums[a] >= target/2:
                for b in range(len(nums)):
                    if a != b and nums[a] + nums[b] == target:
                        return [a, b]
