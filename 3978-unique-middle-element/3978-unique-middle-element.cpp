class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = (nums.size())/2;

        int k = nums[n];
        int c = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == k){
                c++;
            }

            if(c > 1){
                return false;
            }
        }

        return true;
    }
};