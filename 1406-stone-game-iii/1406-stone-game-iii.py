class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        n = len(stoneValue)
        dp = [float('-inf')] * n + [0]
        
        for i in range(n - 1, -1, -1):
            cur_sum = 0
            for k in range(1, 4):
                if i + k <= n:
                    cur_sum += stoneValue[i + k - 1]
                    dp[i] = max(dp[i], cur_sum - dp[i + k])
                    
        if dp[0] > 0:
            return "Alice"
        elif dp[0] < 0:
            return "Bob"
        return "Tie"