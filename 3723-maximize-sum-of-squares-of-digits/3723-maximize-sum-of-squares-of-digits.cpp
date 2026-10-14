class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9LL * num) {
            return "";
        }
        
        string res;
        res.reserve(num);
        
        int nines = sum / 9;
        int rem = sum % 9;
        
        res.append(nines, '9');
        
        if (nines < num) {
            res.push_back(rem + '0');
            res.append(num - nines - 1, '0');
        }
        
        return res;
    }
};