class Solution {
public:
    bool helper(int i, int target, vector<vector<int>>& dp, vector<int>& nums){
        if (target == 0) return true;
        if (i == 0) {
            if (target == nums[i]) return true;
            return false;
        }

        if (dp[i][target] != -1) return dp[i][target];

        bool notTake = helper(i-1, target, dp, nums);
        bool take = false;
        if (target - nums[i] >= 0){
            take = helper(i-1, target - nums[i], dp, nums);
        }

        return dp[i][target] = (take || notTake);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;
        for (int i = 0; i < n; i++){
            total_sum += nums[i];
        }

        if (total_sum % 2 != 0){
            return false;
        }

        int sum = total_sum / 2;

        vector<vector<int>>dp(n, vector<int>(sum+1, -1));
        return helper(n-1, sum, dp, nums);
    }
};