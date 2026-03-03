class Solution {
public:
    int helper(int i, int currXor, vector<int>& nums, vector<vector<int>>& dp){
        if (i >= nums.size()) return currXor;

        if (dp[i][currXor] != -1) return dp[i][currXor];

        int pick = helper(i+1, currXor ^ nums[i], nums, dp);
        int notPick = helper(i+1, currXor, nums, dp);

        return dp[i][currXor] = pick + notPick;
    }
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        vector<vector<int>>dp(n, vector<int>(32, -1));
        return helper(0, 0, nums, dp);
    }
};