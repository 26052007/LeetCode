from bisect import bisect_right
from typing import List

class Solution:
    def stoneGameV(self, stoneValue: List[int]) -> int:
        n = len(stoneValue)
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] = prefix[i] + stoneValue[i]
        
        dp = [[0] * n for _ in range(n)]
        L = [[0] * n for _ in range(n)]
        R = [[0] * n for _ in range(n)]
        
        for i in range(n):
            L[i][i] = stoneValue[i]
            R[i][i] = stoneValue[i]
            
        for length in range(2, n + 1):
            for i in range(n - length + 1):
                j = i + length - 1
                total = prefix[j + 1] - prefix[i]
                mid = bisect_right(prefix, prefix[i] + total // 2) - 2
                
                if mid < i:
                    ans = R[i + 1][j]
                elif 2 * (prefix[mid + 1] - prefix[i]) == total:
                    ans = (prefix[mid + 1] - prefix[i]) + max(dp[i][mid], dp[mid + 1][j])
                    if mid > i:
                        ans = max(ans, L[i][mid - 1])
                    if mid + 1 < j:
                        ans = max(ans, R[mid + 2][j])
                else:
                    ans = L[i][mid]
                    if mid + 1 < j:
                        ans = max(ans, R[mid + 2][j])
                
                dp[i][j] = ans
                L[i][j] = max(L[i][j - 1], total + ans)
                R[i][j] = max(R[i + 1][j], total + ans)
                
        return dp[0][n - 1]