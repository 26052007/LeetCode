class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int e = (n*n)+n;
        int o = (n*n);

        int ans = gcd(e,o);
        return ans; 
    }
};