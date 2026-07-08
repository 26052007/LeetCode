class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        long long mod = 1e9 + 7;
        
        vector<int> V;
        vector<int> cnt(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                V.push_back(s[i] - '0');
                cnt[i + 1] = cnt[i] + 1;
            } else {
                cnt[i + 1] = cnt[i];
            }
        }
        
        int m = V.size();
        vector<long long> val(m + 1, 0);
        vector<long long> S(m + 1, 0);
        vector<long long> p10(m + 1, 1);
        
        for (int i = 0; i < m; i++) {
            val[i + 1] = (val[i] * 10 + V[i]) % mod;
            S[i + 1] = S[i] + V[i];
            p10[i + 1] = (p10[i] * 10) % mod;
        }
        
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (const auto& q : queries) {
            int L = q[0];
            int R = q[1];
            
            int L_v = cnt[L];
            int R_v = cnt[R + 1] - 1;
            
            if (L_v > R_v) {
                ans.push_back(0);
            } else {
                int len = R_v - L_v + 1;
                long long x = (val[R_v + 1] - (val[L_v] * p10[len]) % mod + mod) % mod;
                long long sum = S[R_v + 1] - S[L_v];
                ans.push_back((x * (sum % mod)) % mod);
            }
        }
        
        return ans;
    }
};