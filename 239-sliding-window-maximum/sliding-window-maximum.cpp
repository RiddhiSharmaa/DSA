class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int>mpp;
        vector<int>ans;
        int left = 0;

        for (int right = 0; right < n; right++){
            mpp[nums[right]]++;

            if ((right-left+1) > k){
                mpp[nums[left]]--;
                if (mpp[nums[left]] == 0) mpp.erase(nums[left]);
                left++;
            }

            if ((right-left+1) == k){
                auto it = mpp.rbegin();
                ans.push_back(it -> first);
            }
        }

        return ans;
    }
};