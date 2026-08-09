class Solution {
public:
    string truncateSentence(string s, int k) {
        int n = s.length();
        int index;
        int c= 0;
        for(int i = 0; i < n; i++){
            if(s[i] == ' '){
                c++;
            }

            if(c == k){
                index = i;
                break;
            }
        }

        string ans;
        for(int i = 0; i < index; i++){
            ans += s[i];
        }

        return ans;
    }
};