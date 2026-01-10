class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>mpp;

        for (int i = 0; i < nums.size(); i++){
            int n = target - nums[i];
            if (mpp.find(n) != mpp.end()){
                return {mpp[n], i};
            }

            mpp[nums[i]] = i;
        }

        return {};
    }
};