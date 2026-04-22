class Solution {
public:
    int cnt = 0;
    int helper(int i, int prevIdx, vector<int>& nums, vector<vector<int>>& dp){
        if (i >= nums.size()){
            return 0;
        }
        
        if (dp[i][prevIdx+1] != -1) return dp[i][prevIdx+1];

        int ans1 = 0, ans2 = 0;

        if (prevIdx == -1 || nums[i] > nums[prevIdx]){
            ans1 = 1 + helper(i+1, i, nums, dp);
        }

        ans2 = helper(i+1, prevIdx, nums, dp);

        return dp[i][prevIdx+1] = max(ans1, ans2);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(n+1, -1));

        return helper(0, -1, nums, dp);
    }
};