class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        map<int, int>mpp;
        int left = 0, size = 0;

        for (int right = 0; right < n; right++){
            mpp[nums[right]]++;

            while (mpp.rbegin() -> first - mpp.begin() -> first > limit){
                mpp[nums[left]]--;
                if (mpp[nums[left]] == 0){
                    mpp.erase(nums[left]);
                }
                left++;
            }

            if (mpp.rbegin() -> first - mpp.begin() -> first <= limit){
                size = max(size, right-left+1);
            }
        }

        return size;
    }
};