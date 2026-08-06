class Solution {
public:
    int smallestNumber(int n, int t) {
        bool bhav = false;
        while(bhav == false){
            int sum = 1;
            int ne = n;
            while(ne > 0){
                sum *= ne%10;
                ne/=10;
            }
            if(sum%t == 0){
                bhav = true;
            }
            else{
                n++;
            }
        }

        return n;

    }
};