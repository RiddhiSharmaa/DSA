class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, ansL = 0, ansR = 0;
        map<int, int>mpp;
        vector<int>ans;

        for (int right = 0; right < n; right++){
            mpp[nums[right]]++;

            // shrink window
            while ((right-left+1) > k){
                mpp[nums[left]]--;
                if (mpp[nums[left]] == 0){
                    mpp.erase(nums[left]);
                }
                left++;
            }

            // if condition valid
            if ((right-left+1) == k){
                ans.push_back(mpp.rbegin() -> first);
            }
        }

        return ans;
    }
};