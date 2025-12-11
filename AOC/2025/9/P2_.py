import sys

def solve():
    # Puzzle input: List of red tile coordinates
    # You can replace this string with your actual file reading logic
    # Example input provided in the prompt:
    input_data = open('input.txt', 'r').read()

    # Parse input
    points = []
    for line in input_data.split('\n'):
        if not line.strip():
            continue
        x, y = map(int, line.strip().split(','))
        points.append((x, y))

    # The red tiles form a loop. Create a list of edges.
    # Each edge is ((x1, y1), (x2, y2))
    edges = []
    num_points = len(points)
    for i in range(num_points):
        p1 = points[i]
        p2 = points[(i + 1) % num_points] # Wrap around to start
        edges.append((p1, p2))

    max_area = 0

    # Iterate through every pair of red tiles to form a candidate rectangle
    for i in range(num_points):
        for j in range(i + 1, num_points):
            p1 = points[i]
            p2 = points[j]

            # Determine bounds of the candidate rectangle
            min_x = min(p1[0], p2[0])
            max_x = max(p1[0], p2[0])
            min_y = min(p1[1], p2[1])
            max_y = max(p1[1], p2[1])

            # Calculate potential area: (width + 1) * (height + 1)
            # +1 because the tiles are discrete units (inclusive bounds)
            current_area = (max_x - min_x + 1) * (max_y - min_y + 1)

            # Optimization: Don't check validity if this area is smaller than what we've already found
            if current_area <= max_area:
                continue

            # VALIDITY CHECK 1: Point in Polygon
            # We pick the geometric center of the rectangle.
            # We add a small epsilon (0.5) to avoid landing exactly on grid lines/edges,
            # ensuring we test the "interior" logic correctly.
            mid_x = (min_x + max_x) / 2.0
            mid_y = (min_y + max_y) / 2.0
            
            # Ray Casting Algorithm (Point in Polygon)
            # Cast a ray from (mid_x, mid_y) to (infinity, mid_y)
            intersections = 0
            for edge in edges:
                (x1, y1), (x2, y2) = edge
                
                # Check if the edge crosses the horizontal line of our ray
                # We use strict inequalities > and <= to handle vertices robustly 
                # (ensuring we don't double count corners)
                if (y1 > mid_y) != (y2 > mid_y):
                    # Calculate x-coordinate where the edge crosses the ray's y-level
                    # x = x1 + (y - y1) * (x2 - x1) / (y2 - y1)
                    intersect_x = x1 + (mid_y - y1) * (x2 - x1) / (y2 - y1)
                    if mid_x < intersect_x:
                        intersections += 1
            
            # If intersections is even, point is outside. If odd, inside.
            if intersections % 2 == 0:
                continue

            # VALIDITY CHECK 2: Edge Intersection
            # The rectangle is geometrically inside, but we must ensure no polygon edge
            # cuts through the middle of it (which would mean a chunk of the rect is missing).
            # We check if any polygon edge passes through the *strict interior* of the rectangle.
            is_valid = True
            for edge in edges:
                (ex1, ey1), (ex2, ey2) = edge
                
                # Check for Vertical Edge intersecting Rectangle Interior
                if ex1 == ex2: 
                    # Edge is at x = ex1. Does it fall strictly between min_x and max_x?
                    if min_x < ex1 < max_x:
                        # Does the edge's y-range overlap with the rect's strict interior y-range?
                        edge_y_min, edge_y_max = min(ey1, ey2), max(ey1, ey2)
                        # Overlap check: start < end
                        if max(min_y, edge_y_min) < min(max_y, edge_y_max):
                            is_valid = False
                            break
                
                # Check for Horizontal Edge intersecting Rectangle Interior
                else: # ey1 == ey2
                    # Edge is at y = ey1. Does it fall strictly between min_y and max_y?
                    if min_y < ey1 < max_y:
                        # Does the edge's x-range overlap with the rect's strict interior x-range?
                        edge_x_min, edge_x_max = min(ex1, ex2), max(ex1, ex2)
                        if max(min_x, edge_x_min) < min(max_x, edge_x_max):
                            is_valid = False
                            break
            
            if is_valid:
                max_area = current_area

    print(f"Largest area found: {max_area}")

if __name__ == "__main__":
    solve()
