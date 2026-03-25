class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        unordered_map<int, int>mpp;

        for (int i = 0; i < n; i++){
            int t = target - numbers[i];
            if (mpp.find(t) != mpp.end()){
                int i1 = min(mpp[t]+1, i+1);
                int i2 = max(mpp[t]+1, i+1);
                return {i1, i2};
            }
            mpp[numbers[i]] = i;
        }

        return {};
    }
};