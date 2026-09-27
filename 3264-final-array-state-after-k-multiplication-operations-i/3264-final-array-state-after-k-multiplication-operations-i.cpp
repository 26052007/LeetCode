class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();

        while(k){
            int min = nums[0];
            int index = 0;
            for(int i = 0; i < n; i++){
                if(min > nums[i]){
                    min = nums[i];
                    index = i;
                }
            }
            nums[index]*=multiplier;
            k--;
        }

        return nums;
    }
};