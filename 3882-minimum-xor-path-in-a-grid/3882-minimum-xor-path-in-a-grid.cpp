class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n));
        
        dp[0][0] = {grid[0][0]};
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                
                vector<int> cur;
                if (i > 0) {
                    for (int v : dp[i-1][j]) {
                        cur.push_back(v ^ grid[i][j]);
                    }
                }
                if (j > 0) {
                    for (int v : dp[i][j-1]) {
                        cur.push_back(v ^ grid[i][j]);
                    }
                }
                
                sort(cur.begin(), cur.end());
                cur.erase(unique(cur.begin(), cur.end()), cur.end());
                dp[i][j] = move(cur);
            }
        }
        
        return dp[m-1][n-1][0];
    }
};