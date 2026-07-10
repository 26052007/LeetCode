class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> comp(n);
        comp[0] = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] <= maxDiff) {
                comp[i] = comp[i - 1];
            } else {
                comp[i] = comp[i - 1] + 1;
            }
        }
        
        vector<bool> ans(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            ans[i] = (comp[queries[i][0]] == comp[queries[i][1]]);
        }
        
        return ans;
    }
};