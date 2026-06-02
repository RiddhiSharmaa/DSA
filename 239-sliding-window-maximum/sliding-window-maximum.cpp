class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size(), left = 0;
        priority_queue<pair<int,int>>pq;
        vector<int>ans;

        for (int right = 0; right < n; right++){
            pq.push({nums[right], right});
            if (right-left+1 == k){
                while (!pq.empty() && pq.top().second < left){
                    pq.pop();
                }
                ans.push_back(pq.top().first);
                left++;
            }
        }

        return ans;
    }
};