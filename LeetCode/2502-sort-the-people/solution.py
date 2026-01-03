class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        return [names for _, names in sorted(zip(heights, names), reverse=True)]
