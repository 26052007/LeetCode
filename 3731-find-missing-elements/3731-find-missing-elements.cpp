class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> ans;
        int dak = nums[0];
        int bhav = nums[n-1];
        int i = 0;
        while(dak != bhav){
            if(nums[i] != dak){
                ans.push_back(dak);
            }
            else{
                i++;
            }
            dak++;
            
        }


        return ans;
    }
};