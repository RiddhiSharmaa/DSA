class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (!k || nums.size() == 1) return false;
        unordered_map<int, int>mpp;
        int left = 0, WindowSize = INT_MAX;
        mpp[nums[left]]++;

        for (int right = 1; right < nums.size(); right++){
            mpp[nums[right]]++;

            if ((right - left) > k){
                mpp[nums[left]]--;
                left++;
            }

            while (mpp[nums[right]] > 1){
                if (nums[left] == nums[right] && ((right - left) <= k)){
                    return true;
                }
                mpp[nums[left]]--;
                left++;
            }
        }

        return false;
    }
};