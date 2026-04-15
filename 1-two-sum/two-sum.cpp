class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int>mpp;
        
        for (int i = 0; i < n; i++){
            int remaining = target - nums[i];
            if (mpp.find(remaining) != mpp.end()){
                return {mpp[remaining], i};
            }

            mpp[nums[i]] = i;
        }

        return {};
    }
};