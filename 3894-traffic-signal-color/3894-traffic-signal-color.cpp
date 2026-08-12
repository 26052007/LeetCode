class Solution {
public:
    string trafficSignal(int timer) {
        if(timer == 0){
            string ans = "Green";
            return ans;
        }
        else if(timer == 30){
            string ans = "Orange";
            return ans;
        }
        else if(30 < timer && timer <= 90){
            string ans = "Red";
            return ans;
        }
        else{
            string ans = "Invalid";
            return ans;
        }
    }
};