class Solution {
public:
    bool isPalindrome(string s) {
        
        int l = 0;
        int r = s.length() -1;
        for(int i = 0; i < s.length(); i++){
            if(s[i] >= 65 && s[i] <= 90){
                s[i]+=32;
            }
        }
        bool bhav = true;

        while(l < r){
            if(!isalnum(s[l])){
                l++;
            }
            else if(!isalnum(s[r])){
                r--;
            }
            else{
                if(s[l] != s[r]){
                    bhav = false;
                    break;
                }
                else{
                    l++;
                    r--;
                }
            }
        }
        

        return bhav;
    }
};