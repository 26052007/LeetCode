class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int max_val = 0;
        int n = 0;
        while (n < nums.size()) {
            if (nums[n] > max_val) {
                max_val = nums[n];
            }
            n++;
        }
        
        long long cnt[50005];
        for (int i = 0; i <= max_val; i++) {
            cnt[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            cnt[nums[i]]++;
        }
        
        long long multiples[50005];
        for (int i = 0; i <= max_val; i++) {
            multiples[i] = 0;
        }
        
        for (int i = 1; i <= max_val; i++) {
            for (int j = i; j <= max_val; j += i) {
                multiples[i] += cnt[j];
            }
        }
        
        long long exact_pairs[50005];
        for (int i = 0; i <= max_val; i++) {
            exact_pairs[i] = 0;
        }
        
        for (int i = max_val; i >= 1; i--) {
            exact_pairs[i] = (multiples[i] * (multiples[i] - 1)) / 2;
            for (int j = i * 2; j <= max_val; j += i) {
                exact_pairs[i] -= exact_pairs[j];
            }
        }
        
        long long pref[50005];
        pref[0] = 0;
        for (int i = 1; i <= max_val; i++) {
            pref[i] = pref[i - 1] + exact_pairs[i];
        }
        
        vector<int> ans;
        int q_len = 0;
        while (q_len < queries.size()) {
            q_len++;
        }
        
        for (int i = 0; i < q_len; i++) {
            long long q = queries[i];
            int left = 1;
            int right = max_val;
            int res = max_val;
            
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (pref[mid] > q) {
                    res = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            ans.push_back(res);
        }
        
        return ans;
    }
};