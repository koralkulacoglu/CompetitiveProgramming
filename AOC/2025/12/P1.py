from collections import defaultdict

f = open('input.txt', 'r').read().split('\n\n')

shapes = [[list(y) for y in x.splitlines()[1:]] for x in f[:-1]]
configs = [x.split(': ') for x in f[-1].splitlines()]
rows = 0
cols = 0

def rotate(shape):
    return [list(row) for row in zip(*reversed(shape))]

def flip(shape):
    return [row[::-1] for row in shape]

def canFit(grid, shape, row, col):
    if row + len(shape) > rows or col + len(shape[0]) > cols:
        return False

    for i in range(len(shape)):
        for j in range(len(shape[i])):
            if shape[i][j] == '#' and grid[row+i][col+j]:
                return False

    return True

def updateGrid(grid, shape, row, col):
    for i in range(len(shape)):
        for j in range(len(shape[i])):
            grid[row+i][col+j] |= (shape[i][j] == '#')

    return grid

def printGrid(grid):
    for row in grid:
        for col in row:
            if col:
                print('#', end='')
            else:
                print('.', end='')
        print()
    print()

def printPresent(present):
    for row in present:
        print(''.join(row))
    print()

# dp stores min number of each type of present needed + board state
dp = defaultdict(None)

def dfs(grid, presents):
    # no presents remain
    if sum(presents) == 0:
        return True

    for i in range(len(presents)):
        if presents[i] == 0:
            continue

        shape = shapes[i]
        orientations = []
        for rotations in range(4):
            shape = rotate(shape)
            flippedShape = flip(shape)

            if shape not in orientations:
                orientations.append(shape)

            if flippedShape not in orientations:
                orientations.append(flippedShape)

        for orientation in orientations:
            fails = False
            # try adding it to the top leftmost spot
            for row in range(rows):
                for col in range(cols):
                    if not canFit(grid, orientation, row, col):
                        continue

                    newGrid = updateGrid(grid, orientation, row, col)
                    newPresents = presents
                    newPresents[i] -= 1

                    if dfs(newGrid, newPresents):
                        return True
                    else:
                        fails = True
                        break
                if fails:
                    break

    return False

ans = 0
for config in configs:
    cols, rows = map(int, config[0].split('x'))
    presents = list(map(int, config[1].split()))

    grid = [[False for j in range(cols)] for i in range(rows)]
    possible = dfs(grid, presents)
    print(f'Config {config}: {possible}')

    ans += possible

print(ans)
