class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        return s in goal*2 and len(s) <= len(goal)
