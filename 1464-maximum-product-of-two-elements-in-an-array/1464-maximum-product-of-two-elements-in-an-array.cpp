class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int max = 0;
        int index;
        for(int i = 0;i < n; i++){
            if(nums[i] > max){
                max = nums[i];
                index = i;
            }
        }

        int sec = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] > sec && i != index){
                sec = nums[i];
            }
        }

        int ans = (max-1)*(sec-1);
        return ans;
    }
};