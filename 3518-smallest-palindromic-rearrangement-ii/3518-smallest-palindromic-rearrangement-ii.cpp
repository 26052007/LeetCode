class Solution {
public:
    string smallestPalindrome(string s, int k) {
        vector<int> counts(26, 0);
        for (char c : s) {
            counts[c - 'a']++;
        }
        
        vector<int> half(26, 0);
        string mid = "";
        int m = 0;
        
        for (int i = 0; i < 26; i++) {
            if (counts[i] % 2 != 0) {
                mid += (char)('a' + i);
            }
            half[i] = counts[i] / 2;
            m += half[i];
        }
        
        auto get_ways = [&](vector<int>& h) {
            long long ways = 1;
            int total = 0;
            for (int c : h) {
                if (c == 0) continue;
                for (int i = 1; i <= c; i++) {
                    total++;
                    if (ways == 1 && total == i) continue;
                    __int128 next_ways = (__int128)ways * total / i;
                    if (next_ways > 2000000000000000000LL) {
                        return 2000000000000000001LL;
                    }
                    ways = (long long)next_ways;
                }
            }
            return ways;
        };
        
        long long total_palis = get_ways(half);
        if (k > total_palis) return "";
        
        string left = "";
        long long cur_k = k;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < 26; j++) {
                if (half[j] > 0) {
                    half[j]--;
                    long long w = get_ways(half);
                    if (cur_k <= w) {
                        left += (char)('a' + j);
                        break;
                    } else {
                        cur_k -= w;
                        half[j]++;
                    }
                }
            }
        }
        
        string right = left;
        reverse(right.begin(), right.end());
        
        return left + mid + right;
    }
};