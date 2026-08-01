class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });

        int ans = 0;
        int curr = 0;
        for (const auto& task : tasks) {
            if (curr < task[1]) {
                ans += task[1] - curr;
                curr = task[1];
            }
            curr -= task[0];
        }
        return ans;
    }
};