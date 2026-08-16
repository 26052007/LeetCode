class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n = stones.size();

        int sum = 0;
        int one = 0;
        int two = 0;
        int zero = 0;
        for(int i =0; i <n; i++){
            sum += stones[i];
            if(stones[i]%3 == 1){
                one++;
            }
            else if(stones[i]%3 == 2){
                two++;
            }
            else zero++;
        }

        if(zero%2 == 0){
            if(one >=1 && two>=1){
                return true;
            }
            else return false;
        }
        else{
            if(abs(one-two) > 2) return true;
            else return false;
        }

        

    }
};