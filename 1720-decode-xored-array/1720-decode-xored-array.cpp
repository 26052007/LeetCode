class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size();

        vector<int> v(n+1);
        v[0] = first;
        for(int i = 0; i < n; i++){
            v[i+1] = encoded[i]^v[i];
        }

        return v;

    }
};