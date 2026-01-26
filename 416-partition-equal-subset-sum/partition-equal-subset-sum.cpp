class Solution {
public:
    bool helper(int i, int target, vector<int>& nums, vector<vector<int>>& dp){
        if (target == 0) return true;
        if (i >= nums.size()) return false;
        if (dp[i][target] != -1) return dp[i][target];

        int pick = 0;
        if (target - nums[i] >= 0){
            pick = helper(i+1, target - nums[i], nums, dp);
        }
        int notPick = helper(i+1, target, nums, dp);

        return dp[i][target] = pick + notPick;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++){
            sum += nums[i];
        }

        if (sum % 2 != 0) return false;
        int target = sum/2;
        vector<vector<int>>dp(n, vector<int>(target+1, -1));

        return helper(0, target, nums, dp);
    }
};