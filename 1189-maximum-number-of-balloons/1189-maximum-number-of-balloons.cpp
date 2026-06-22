class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.length();

        vector<int> v(26,0);
        for(int i = 0; i < n; i++){
            v[text[i]-'a']++;
        }

        int d = v[11]/2 ;
        int e = v[14]/2;
        int ans = min({v[0],v[1],d,v[13],e});

        return ans;
    }
};