import matplotlib.pyplot as plt

# we could also just brute force this very easily
# idea: just brute force
# nvm the grid is huge
# can we store that number in memory??
# kinda
# the algorithm will be a bit slow
# it will be really slow but it works

# idea: first connect all red tiles via green tiles
# then do some sort of dfs?????

# maybe we visualize this and do it manually?
# might be possible

# i have no idea how to solve this

# i have a crazy feeling that we can just pick the best 2 coordinates like in P1

# idea: pick 2 points and see if there's another point inbetween them
# if so then discard otherwise set the answer to the max dist of those

a = [list(map(int, x.split(','))) for x in open('input.txt', 'r').read().splitlines()]

x_values = [point[0] for point in a]
y_values = [point[1] for point in a]

plt.figure(figsize=(10, 8))
plt.scatter(x_values, y_values, s=10, alpha=0.5)

plt.title("Coordinate Visualization")
plt.xlabel("X")
plt.ylabel("Y")
plt.grid(True, linestyle='--', alpha=0.6)

plt.savefig('tiles.png')

# check if there's a colorless tile inside the rectangle
# we need to go from point 1 to point 2 and see if the rectangle ever hits a colorless tile
# this is hard

CENTER_X = 50000
CENTER_Y = 50000

# Squared thresholds to avoid slow sqrt() calls
# Radius ~44,000 -> 44000^2 = 1,936,000,000
# Radius ~50,000 -> 50000^2 = 2,500,000,000
MIN_R_SQ = 1936000000
MAX_R_SQ = 2500000000

def area(p1, p2):
    return (1 + abs(p1[0] - p2[0])) * (1 + abs(p1[1] - p2[1]))

def is_point_on_ring(p):
    # Calculate squared distance from center
    dx = p[0] - CENTER_X
    dy = p[1] - CENTER_Y
    dist_sq = dx*dx + dy*dy

    # Check if point falls inside the ring's thickness
    return MIN_R_SQ <= dist_sq <= MAX_R_SQ

def isValid(p1, p2):
    # A pair is valid only if BOTH points are on the ring
    return is_point_on_ring(p1) and is_point_on_ring(p2)

ans = 0

# Pre-filter the list to avoid O(N^2) checks on invalid points
# This makes the main loop much faster
valid_points = [p for p in a if is_point_on_ring(p)]

for p1 in valid_points:
    for p2 in valid_points:
        # We don't need isValid here anymore since we pre-filtered
        ans = max(ans, area(p1, p2))

print(ans)
