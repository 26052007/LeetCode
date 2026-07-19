class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last_occurrence(26, 0);
        vector<bool> in_stack(26, false);
        string result = "";

        for (int i = 0; i < s.length(); ++i) {
            last_occurrence[s[i] - 'a'] = i;
        }

        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            
            if (in_stack[c - 'a']) {
                continue;
            }
            
            while (!result.empty() && result.back() > c && last_occurrence[result.back() - 'a'] > i) {
                in_stack[result.back() - 'a'] = false;
                result.pop_back();
            }
            
            result.push_back(c);
            in_stack[c - 'a'] = true;
        }

        return result;
    }
};
