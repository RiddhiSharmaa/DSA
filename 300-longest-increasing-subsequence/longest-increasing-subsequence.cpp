class Solution {
public:
    int dp[2501][2501];
    int helper(int i, int prev, vector<int>& nums){
        if (i >= nums.size()) return 0;
        if (dp[i][prev+1] != -1) return dp[i][prev+1];

        int ans1 = -1, ans2 = -1;
        if (prev == -1 || nums[i] > nums[prev]){
            ans1 = 1 + helper(i+1, i, nums);
        }
        ans2 = helper(i+1, prev, nums);

        return dp[i][prev+1] = max(ans1, ans2);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));

        return helper(0, -1, nums);
    }
};