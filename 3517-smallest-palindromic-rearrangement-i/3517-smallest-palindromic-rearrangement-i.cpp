class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        
        string left = "";
        char mid = 0;
        
        for (int i = 0; i < 26; i++) {
            if (count[i] % 2 != 0) {
                mid = 'a' + i;
            }
            left.append(count[i] / 2, 'a' + i);
        }
        
        string right = left;
        reverse(right.begin(), right.end());
        
        if (mid != 0) {
            return left + mid + right;
        }
        return left + right;
    }
};