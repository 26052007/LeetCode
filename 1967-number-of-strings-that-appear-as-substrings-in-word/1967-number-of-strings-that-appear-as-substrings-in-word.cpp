class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n = patterns.size();
        int c= 0;
        for(int i = 0; i < n; i++){
            bool bhav = word.contains(patterns[i]);
            if(bhav) c++;
            else continue;
        }

        return c;
    }
};