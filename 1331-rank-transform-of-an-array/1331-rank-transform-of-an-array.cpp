class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        
        unordered_map<int, int> ranks;
        int currentRank = 1;
        
        for (int i = 0; i < sortedArr.size(); i++) {
            if (ranks.find(sortedArr[i]) == ranks.end()) {
                ranks[sortedArr[i]] = currentRank;
                currentRank++;
            }
        }
        
        vector<int> result;
        for (int i = 0; i < arr.size(); i++) {
            result.push_back(ranks[arr[i]]);
        }
        
        return result;
    }
};