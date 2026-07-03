class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        vector<int> costs;
        
        for (const auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            costs.push_back(e[2]);
        }
        
        sort(costs.begin(), costs.end());
        costs.erase(unique(costs.begin(), costs.end()), costs.end());
        
        int ans = -1;
        int left = 0, right = (int)costs.size() - 1;
        
        vector<long long> memo(n);
        
        auto dfs = [&](auto& self, int u, int min_req) -> long long {
            if (u == n - 1) return 0;
            if (memo[u] != -2) return memo[u];
            
            long long res = -1;
            for (const auto& edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;
                
                if (w < min_req) continue;
                if (v != n - 1 && !online[v]) continue;
                
                long long nxt = self(self, v, min_req);
                if (nxt != -1) {
                    if (res == -1 || nxt + w < res) {
                        res = nxt + w;
                    }
                }
            }
            return memo[u] = res;
        };
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int min_required_cost = costs[mid];
            
            fill(memo.begin(), memo.end(), -2);
            long long min_cost = dfs(dfs, 0, min_required_cost);
            
            if (min_cost != -1 && min_cost <= k) {
                ans = min_required_cost;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return ans;
    }
};