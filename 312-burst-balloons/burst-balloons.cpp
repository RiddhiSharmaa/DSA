class Solution {
public:
    int dp[301][301];
    int helper(int i, int j, vector<int>& nums){
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        for (int k = i; k <= j; k++){
            int tempAns = helper(i, k-1, nums) + helper(k+1, j, nums) + 
            nums[k] * nums[i-1] * nums[j+1];
            ans = max(ans, tempAns);
        }
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        memset(dp, -1, sizeof(dp));
        return helper(1, n, nums);
    }
};