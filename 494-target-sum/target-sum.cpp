class Solution {
public:
    int dp[21][2001];
    int helper(int i, int target, int& t, vector<int>& nums){
        if (i == nums.size()){
            if (target == t) return 1;
            return 0;
        }
        if (i > nums.size()) return 0;
        if (dp[i][1000+target] != -1) return dp[i][1000+target];
        int pos = helper(i+1, target+nums[i], t, nums);
        int neg = helper(i+1, target-nums[i], t, nums);
        return dp[i][1000+target] = pos + neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        return helper(0, 0, target, nums);
    }
};