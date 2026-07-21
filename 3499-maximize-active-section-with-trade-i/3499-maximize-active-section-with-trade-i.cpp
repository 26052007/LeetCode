class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string t = "1" + s + "1";
        vector<int> L, Z;
        int n = t.length();
        int i = 0;
        
        while (i < n) {
            int j = i;
            while (j < n && t[j] == t[i]) j++;
            if (t[i] == '1') {
                L.push_back(j - i);
            } else {
                Z.push_back(j - i);
            }
            i = j;
        }
        
        int initial_ones = 0;
        for (char c : s) {
            if (c == '1') {
                initial_ones++;
            }
        }
        
        int m = Z.size();
        if (m <= 1) {
            return initial_ones;
        }
        
        vector<int> pref(m, 0), suff(m, 0);
        pref[0] = Z[0];
        for (int k = 1; k < m; k++) {
            pref[k] = max(pref[k-1], Z[k]);
        }
        
        suff[m-1] = Z[m-1];
        for (int k = m - 2; k >= 0; k--) {
            suff[k] = max(suff[k+1], Z[k]);
        }
        
        int max_net_change = 0;
        for (int k = 1; k < m; k++) {
            int merged_Z = Z[k-1] + L[k] + Z[k];
            int max_other_Z = 0;
            
            if (k - 2 >= 0) {
                max_other_Z = max(max_other_Z, pref[k-2]);
            }
            if (k + 1 < m) {
                max_other_Z = max(max_other_Z, suff[k+1]);
            }
            
            int best_Z = max(merged_Z, max_other_Z);
            int net_change = best_Z - L[k];
            max_net_change = max(max_net_change, net_change);
        }
        
        return initial_ones + max_net_change;
    }
};