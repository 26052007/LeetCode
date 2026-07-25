class Solution {
public:
    int maxProduct(int n) {
        vector<int> v;
        while(n>0){
            int c = n%10;
            v.push_back(c);
            n/=10;
        }

        sort(v.begin(),v.end());
        int m = v.size();
        int ans = v[m-1]*v[m-2];
        return ans;
    }
};