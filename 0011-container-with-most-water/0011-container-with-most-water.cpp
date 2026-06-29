class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int l = 0;
        int r = n-1;

        int max = 0;
        while(l < r){
            int current = (abs(l-r)*min(height[l],height[r]));

            if(current > max){
                max = current;
            }

            if(height[l] < height[r]){
                l++;
            }
            else{
                r--;
            }

        }

        return max;
    }
};