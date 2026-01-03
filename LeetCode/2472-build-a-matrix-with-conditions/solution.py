def toposort(graph):
    res, found = [], [0] * len(graph)
    stack = list(range(len(graph)))
    while stack:
        node = stack.pop()
        if node < 0:
            res.append(~node)
        elif not found[node]:
            found[node] = 1
            stack.append(~node)
            stack += graph[node]

    # cycle check
    for node in res:
        if any(found[nei] for nei in graph[node]):
            return None
        found[node] = 0

    return res[::-1]


class Solution:
    def buildMatrix(self, k: int, above_conditions: List[List[int]], left_conditions: List[List[int]]) -> List[List[int]]:
        above = [[] for _ in range(k)]
        for x, y in above_conditions:
            above[x - 1].append(y - 1)

        left = [[] for _ in range(k)]
        for x, y in left_conditions:
            left[x - 1].append(y - 1)

        above_order, left_order = toposort(above), toposort(left)
        if above_order is None or left_order is None:
            return []

        return [
            [j + 1 if j == k else 0 for k in left_order]
            for i, j in enumerate(above_order)
        ]

