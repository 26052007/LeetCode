class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();

        int c = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] < k){
                c++;
            }
        }

        return c;
    }
};