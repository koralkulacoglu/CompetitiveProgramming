class Solution:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        return max(len(moves) - 2*moves.count('L'), len(moves) - 2*moves.count('R'))
