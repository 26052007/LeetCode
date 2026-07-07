class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(),nums.end());

        vector<float> v;
        for(int i = 0; i < n/2; i++){
            v.push_back(((float)nums[i]+nums[n-i-1])/2);
        }

        float min = v[0];
        for(int i = 0; i < v.size(); i++){
            if(v[i] < min){
                min = v[i];
            }
        }

        return min;

    }
};