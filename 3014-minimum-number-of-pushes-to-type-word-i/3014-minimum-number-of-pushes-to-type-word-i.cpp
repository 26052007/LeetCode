class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();

        int c= 0;
        if(n < 8){
            return n;
        }
        else if(n >= 8 && n < 16){
            int ans = (n%8)*2;
            return 8+ans;
        }
        else if(n >= 16 && n<24){
            int ans = (n%8)*3;
            return 24+ans;
        }
        else{
            int ans = (n%8)*4;
            return 48+ans;
        }
    }
};