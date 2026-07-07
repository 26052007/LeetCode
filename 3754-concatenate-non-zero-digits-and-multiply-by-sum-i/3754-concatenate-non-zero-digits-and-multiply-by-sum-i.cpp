class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        int a = n,b= n;
        while(a > 0){
            sum += a%10;
            a/=10;
        }

        long long x = 0;
        int i = 1;
        while(b > 0){
            if(b%10 != 0){
                x += (b%10)*i;
                i*=10;
                b/=10;
            }
            else{
                b/=10;
            }
        }


        return sum*x;
    }
};