class Solution {
public:
    int countDigits(int num) {
        int c = 0;
        int n = num;
        while(n){
            if(n%10 != 0 && num%(n%10) == 0){
                c++;
            }
            n/=10;
        }
        return c;
    }
};