class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        return len(set(sum([[''.join(p) for p in permutations(tiles, i)] for i in range(1, len(tiles)+1)], [])))

