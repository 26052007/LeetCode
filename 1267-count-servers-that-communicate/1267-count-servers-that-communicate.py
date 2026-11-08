from typing import List

class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        row_counts = [sum(row) for row in grid]
        col_counts = [sum(grid[i][j] for i in range(m)) for j in range(n)]
        
        ans = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    if row_counts[i] > 1 or col_counts[j] > 1:
                        ans += 1
                        
        return ans