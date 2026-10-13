class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        sort(nums.begin(), nums.end(), [](int a, int b){
            return abs(a) < abs(b);
        });
        
        if(n%2 == 0){
            for(int i = n/2; i < n; i++){
                sum += (long long)nums[i]*nums[i];
            }
            for(int i = 0; i < n/2; i++){
                sum -= (long long)nums[i]*nums[i];
            }
        }
        else{
            for(int i = (n/2); i < n; i++){
                sum += (long long)nums[i]*nums[i];
            }
            for(int i = 0; i < (n/2); i++){
                sum -= (long long)nums[i]*nums[i];
            }
        }
        return sum;
        
    }
};