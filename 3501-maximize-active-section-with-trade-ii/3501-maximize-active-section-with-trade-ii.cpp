class Solution {
    class SegmentTree {
        int n;
        vector<int> tree;
    public:
        SegmentTree(const vector<int>& arr) {
            n = arr.size();
            if (n > 0) {
                tree.assign(4 * n, 0);
                build(arr, 1, 0, n - 1);
            }
        }
        void build(const vector<int>& arr, int node, int start, int end) {
            if (start == end) {
                tree[node] = arr[start];
            } else {
                int mid = (start + end) / 2;
                build(arr, 2 * node, start, mid);
                build(arr, 2 * node + 1, mid + 1, end);
                tree[node] = max(tree[2 * node], tree[2 * node + 1]);
            }
        }
        int query(int node, int start, int end, int l, int r) {
            if (r < start || end < l) return 0;
            if (l <= start && end <= r) return tree[node];
            int mid = (start + end) / 2;
            int p1 = query(2 * node, start, mid, l, r);
            int p2 = query(2 * node + 1, mid + 1, end, l, r);
            return max(p1, p2);
        }
        int query(int l, int r) {
            if (l > r || n == 0) return 0;
            return query(1, 0, n - 1, l, r);
        }
    };

public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int total_ones = 0;
        for (char c : s) if (c == '1') total_ones++;
        
        vector<pair<int, int>> blocks;
        vector<int> block_idx(n, -1);
        for(int i = 0; i < n; ) {
            if (s[i] == '0') {
                int j = i;
                while(j < n && s[j] == '0') j++;
                blocks.push_back({i, j - 1});
                for(int k = i; k < j; k++) block_idx[k] = blocks.size() - 1;
                i = j;
            } else {
                i++;
            }
        }
        
        vector<int> next_block(n, -1);
        int curr_next = -1;
        for(int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') curr_next = block_idx[i];
            next_block[i] = curr_next;
        }

        vector<int> prev_block(n, -1);
        int curr_prev = -1;
        for(int i = 0; i < n; i++) {
            if (s[i] == '0') curr_prev = block_idx[i];
            prev_block[i] = curr_prev;
        }
        
        int K = blocks.size();
        vector<int> A;
        if (K > 1) {
            A.resize(K - 1);
            for(int i = 0; i < K - 1; i++) {
                A[i] = (blocks[i].second - blocks[i].first + 1) + 
                       (blocks[i+1].second - blocks[i+1].first + 1);
            }
        }
        SegmentTree st(A);
        
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            int p = next_block[l];
            int qu = prev_block[r];
            
            int gain = 0;
            if (p != -1 && qu != -1 && p < qu) {
                auto get_len = [&](int idx) {
                    return min(r, blocks[idx].second) - max(l, blocks[idx].first) + 1;
                };
                
                int left_len = get_len(p);
                int right_len = get_len(qu);
                
                if (p + 1 == qu) {
                    gain = left_len + right_len;
                } else {
                    int L_p1 = blocks[p+1].second - blocks[p+1].first + 1;
                    int L_qum1 = blocks[qu-1].second - blocks[qu-1].first + 1;
                    
                    gain = max(left_len + L_p1, L_qum1 + right_len);
                    if (qu - 2 >= p + 1) {
                        gain = max(gain, st.query(p + 1, qu - 2));
                    }
                }
            }
            ans.push_back(total_ones + gain);
        }
        
        return ans;
    }
};