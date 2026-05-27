class Solution {
public:
    int helper(int i, vector<int>& dp, vector<int>& nums){
        if (i >= nums.size()) return 0;
        if (dp[i] != -1) return dp[i];

        int notPick = helper(i+1, dp, nums);
        int pick = nums[i] + helper(i+2, dp, nums);

        return dp[i] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, -1);

        return helper(0, dp, nums);
    }
};