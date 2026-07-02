class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> rowMins(m, 1000000);
        vector<int> colMaxs(n, 0);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rowMins[i] = min(rowMins[i], matrix[i][j]);
                colMaxs[j] = max(colMaxs[j], matrix[i][j]);
            }
        }

        vector<int> ans;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == rowMins[i] && matrix[i][j] == colMaxs[j]) {
                    ans.push_back(matrix[i][j]);
                }
            }
        }

        return ans;
    }
};