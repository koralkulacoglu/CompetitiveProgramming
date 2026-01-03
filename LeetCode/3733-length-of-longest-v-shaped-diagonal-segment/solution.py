class Solution:
    def lenOfVDiagonal(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        # Diagonals: NE, SE, SW, NW
        dirs: List[Tuple[int, int]] = [(-1, 1), (1, 1), (1, -1), (-1, -1)]
        clockwise = [1, 2, 3, 0]  # NE->SE->SW->NW->NE

        def inb(r, c): return 0 <= r < n and 0 <= c < m

        # Alternating tails (no turn), starting with 2 vs 0 at (i,j)
        run2 = [[[0]*m for _ in range(n)] for _ in range(4)]
        run0 = [[[0]*m for _ in range(n)] for _ in range(4)]

        def fill_runs_for_dir(d: int):
            dr, dc = dirs[d]
            rdr, rdc = -dr, -dc  # traverse so forward neighbor is prefilled
            starts = [(i, j) for i in range(n) for j in range(m)
                    if not inb(i+dr, j+dc)]
            for si, sj in starts:
                i, j = si, sj
                while inb(i, j):
                    fr, fc = i+dr, j+dc
                    nr2 = run2[d][fr][fc] if inb(fr, fc) else 0
                    nr0 = run0[d][fr][fc] if inb(fr, fc) else 0
                    v = grid[i][j]
                    if v == 2:
                        run2[d][i][j] = 1 + nr0
                        run0[d][i][j] = 0
                    elif v == 0:
                        run0[d][i][j] = 1 + nr2
                        run2[d][i][j] = 0
                    else:
                        run2[d][i][j] = run0[d][i][j] = 0
                    i += rdr; j += rdc

        for d in range(4):
            fill_runs_for_dir(d)

        # First-leg prefixes along d, anchored by a preceding 1.
        # Valid start is ONLY 1->2 (never 1->0).
        pre2s = [[[0]*m for _ in range(n)] for _ in range(4)]  # end value 2
        pre0s = [[[0]*m for _ in range(n)] for _ in range(4)]  # end value 0

        def fill_first_leg_for_dir(d: int):
            dr, dc = dirs[d]
            starts = [(i, j) for i in range(n) for j in range(m)
                    if not inb(i-dr, j-dc)]
            for si, sj in starts:
                i, j = si, sj
                while inb(i, j):
                    pr, pc = i-dr, j-dc
                    v = grid[i][j]
                    if inb(pr, pc):
                        pv = grid[pr][pc]
                        if v == 2:
                            if pv == 1:
                                pre2s[d][i][j] = 1         # start 1->2
                            elif pre0s[d][pr][pc] > 0:
                                pre2s[d][i][j] = pre0s[d][pr][pc] + 1
                            else:
                                pre2s[d][i][j] = 0
                            pre0s[d][i][j] = 0
                        elif v == 0:
                            if pre2s[d][pr][pc] > 0:      # extend …2 -> 0
                                pre0s[d][i][j] = pre2s[d][pr][pc] + 1
                            else:
                                pre0s[d][i][j] = 0
                            pre2s[d][i][j] = 0
                        else:
                            pre2s[d][i][j] = pre0s[d][i][j] = 0
                    else:
                        pre2s[d][i][j] = pre0s[d][i][j] = 0
                    i += dr; j += dc

        for d in range(4):
            fill_first_leg_for_dir(d)

        # Combine: no-turn and single clockwise turn.
        if not any(1 in row for row in grid):
            return 0
        ans = 1  # any 1 alone

        for d1 in range(4):
            d2 = clockwise[d1]
            dr2, dc2 = dirs[d2]
            for i in range(n):
                for j in range(m):
                    # First leg ends with 2 -> after turn must start with 0
                    r = pre2s[d1][i][j]
                    if r > 0:
                        ans = max(ans, 1 + r)
                        ni, nj = i + dr2, j + dc2
                        if 0 <= ni < n and 0 <= nj < m:
                            ans = max(ans, 1 + r + run0[d2][ni][nj])
                    # First leg ends with 0 -> after turn must start with 2
                    r = pre0s[d1][i][j]
                    if r > 0:
                        ans = max(ans, 1 + r)
                        ni, nj = i + dr2, j + dc2
                        if 0 <= ni < n and 0 <= nj < m:
                            ans = max(ans, 1 + r + run2[d2][ni][nj])
        return ans

