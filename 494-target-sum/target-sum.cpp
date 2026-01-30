class Solution {
public:
    int helper(int i, int target, int &sum, vector<int>& nums, vector<vector<int>>& dp){
        if (i == nums.size() && target == 0) return 1;
        if (i >= nums.size()) return 0;
        if (target > sum || target < -sum) return 0;

        if (dp[i][target+sum] != -1) return dp[i][target+sum];

        int sub = helper(i+1, target + nums[i], sum, nums, dp);
        int add = helper(i+1, target - nums[i], sum, nums, dp);

        return dp[i][target+sum] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(), sum = 0;
        for (int i = 0; i < nums.size(); i++) sum += nums[i];
        vector<vector<int>>dp(n, vector<int>((2*sum)+1, -1));
        return helper(0, target, sum, nums, dp);
    }
};