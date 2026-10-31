
class Solution:
    def uniquePaths(self, grid: List[List[int]]) -> int:
        mod = 10**9 + 7
        m = len(grid)
        n = len(grid[0])

        if grid[m-1][n-1] == 1:
            return 0

        dp_r = [[0] * n for _ in range(m)]
        dp_d = [[0] * n for _ in range(m)]

        if m == 1 and n == 1:
            return 1

        if n > 1:
            dp_r[0][1] = 1

        if m > 1:
            dp_d[1][0] = 1

        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    continue

                if grid[i][j] == 0:
                    ways = (dp_r[i][j] + dp_d[i][j]) % mod

                    if j + 1 < n:
                        dp_r[i][j+1] = (dp_r[i][j+1] + ways) % mod

                    if i + 1 < m:
                        dp_d[i+1][j] = (dp_d[i+1][j] + ways) % mod

                else:
                    if i + 1 < m:
                        dp_d[i+1][j] = (dp_d[i+1][j] + dp_r[i][j]) % mod

                    if j + 1 < n:
                        dp_r[i][j+1] = (dp_r[i][j+1] + dp_d[i][j]) % mod

        return (dp_r[m-1][n-1] + dp_d[m-1][n-1]) % mod
