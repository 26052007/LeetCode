class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    q.push({r, c});
                    dist[r][c] = 0;
                }
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (auto& d : dir) {
                int nr = r + d.first;
                int nc = c + d.second;
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        pq.push({dist[0][0], {0, 0}});
        vis[0][0] = true;

        while (!pq.empty()) {
            auto [safe, pos] = pq.top();
            auto [r, c] = pos;
            pq.pop();

            if (r == n - 1 && c == n - 1) {
                return safe;
            }

            for (auto& d : dir) {
                int nr = r + d.first;
                int nc = c + d.second;
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !vis[nr][nc]) {
                    vis[nr][nc] = true;
                    pq.push({min(safe, dist[nr][nc]), {nr, nc}});
                }
            }
        }

        return 0;
    }
};