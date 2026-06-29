class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        deque<int>dq;
        vector<int>ans;

        for (int right = 0; right < n; right++){
            while (!dq.empty() && nums[dq.back()] < nums[right]){
                dq.pop_back();
            }
            dq.push_back(right);

            if (right-left+1 > k){
                if (dq.front() == left){
                    dq.pop_front();
                }
                left++;
            }

            if (right-left+1 == k){
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};