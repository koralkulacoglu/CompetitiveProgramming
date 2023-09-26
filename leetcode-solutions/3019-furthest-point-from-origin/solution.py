class Solution:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        left = moves.count('L')
        right = moves.count('R')        
        free = moves.count('_')        
        
        return max(left+free-right, right+free-left)
