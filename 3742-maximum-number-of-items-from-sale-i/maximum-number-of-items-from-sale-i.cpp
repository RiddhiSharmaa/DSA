class Solution {
public:
    int helper(int i, int target, int& mini, vector<vector<int>>& dp, 
        vector<int>& mpp, vector<vector<int>>& items){
        if (i >= items.size()) return target/mini;
        if (dp[i][target] != -1) return dp[i][target];

        int pick = 0;
        if (target - items[i][1] >= 0){
            pick = 1 + mpp[i] + helper(i+1, target - items[i][1], mini, dp, mpp, items);
        }

        int notPick = helper(i+1, target, mini, dp, mpp, items);

        return dp[i][target] = max(pick, notPick);
        }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int>mpp(n, 0);
        vector<vector<int>>dp(n+1, vector<int>(budget+1, -1));
        int mini = INT_MAX;

        for (int i = 0; i < n; i++){
            mini = min(mini, items[i][1]);
            for (int j = 0; j < n; j++){
                if (j != i && items[j][0] % items[i][0] == 0){
                    mpp[i]++;
                }
            }
        }

        return helper(0, budget, mini, dp, mpp, items);
    }
};