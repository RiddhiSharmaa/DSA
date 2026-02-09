class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        vector<int>ans;
        deque<int>dq;

        for (int right = 0; right < n; right++){
            while (!dq.empty() && nums[dq.back()] < nums[right]){
                dq.pop_back();
            }
            dq.push_back(right);

            //shrink the window
            while ((right-left+1) > k){
                if (left == dq.front()){
                    dq.pop_front();
                }
                left++;
            }

            // if window is valid
            if ((right-left+1) == k){
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};