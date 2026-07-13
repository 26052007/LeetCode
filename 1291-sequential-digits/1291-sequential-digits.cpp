class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string digits = "123456789";
        vector<int> result;
        
        for (int len = 2; len <= 9; ++len) {
            for (int i = 0; i <= 9 - len; ++i) {
                int num = stoi(digits.substr(i, len));
                if (num >= low && num <= high) {
                    result.push_back(num);
                }
            }
        }
        
        return result;
    }
};