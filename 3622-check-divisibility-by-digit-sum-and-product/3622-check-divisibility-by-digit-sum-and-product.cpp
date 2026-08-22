class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int product = 1;
        int ne = n;
        while(n>0){
            sum += n%10;
            product *= n%10;
            n/=10;
        }

        int ans =  sum+product;
        if(ne%ans == 0) return true;
        else return false;
    }
};