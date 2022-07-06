class Graph:
    def __init__(self, row, col, graph):
        self.ROW = row
        self.COL = col
        self.graph = graph
 
    def DFS(self, i, j):
        if i < 0 or i >= len(self.graph) or j < 0 or j >= len(self.graph[0]) or self.graph[i][j] != '1':
            return
 
        self.graph[i][j] = -1
        self.DFS(i - 1, j)
        self.DFS(i, j - 1)
        self.DFS(i, j + 1)
        self.DFS(i + 1, j)
 
    def countIslands(self):
        count = 0
        for i in range(self.ROW):
            for j in range(self.COL):
                if self.graph[i][j] == '1':
                    self.DFS(i, j)
                    count += 1
 
        return count

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        return Graph(len(grid), len(grid[0]), grid).countIslands()

