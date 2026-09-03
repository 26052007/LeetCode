class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int e = 0;
        int o = 0;
        int min = nums1[0];
        for(int i = 0 ; i < n; i++){
            if(nums1[i]%2 == 0) e++;
            else o++;

            if(min > nums1[i]){
                min = nums1[i];
            }
        }

        if(e == 0 || o == 0) return true;

        if( min%2 == 0){
            return false;
        }

        return true;
    }
};