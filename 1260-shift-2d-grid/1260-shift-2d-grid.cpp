class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int new_pos = (i * n + j + k) % (m * n);
                ans[new_pos / n][new_pos % n] = grid[i][j];
            }
        }
        
        return ans;
    }
};