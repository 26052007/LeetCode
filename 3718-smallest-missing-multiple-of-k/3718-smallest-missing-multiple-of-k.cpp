class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(),nums.end());

        int d = k;
        for(int i = 0;i < n; i++){
            if(nums[i] == d){
                d+=k;
            }
        }

        return d;
        
    }
};