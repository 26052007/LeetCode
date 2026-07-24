class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> unique_nums(nums.begin(), nums.end());
        vector<int> u(unique_nums.begin(), unique_nums.end());
        int n = u.size();
        
        unordered_set<int> pairs;
        for(int i = 0; i < n; ++i) {
            for(int j = i; j < n; ++j) {
                pairs.insert(u[i] ^ u[j]);
            }
        }
        
        unordered_set<int> ans;
        for(int x : pairs) {
            for(int y : u) {
                ans.insert(x ^ y);
            }
        }
        
        return ans.size();
    }
};