class Solution {
public:
    int helper(int i, int buy, int tr, vector<int>& prices, vector<vector<vector<int>>>& dp){
        if (tr >= 2) return 0;
        if (i >= prices.size()) return 0;
        if (dp[i][buy][tr] != -1) return dp[i][buy][tr];

        int profit = 0;
        if (buy == 1){
            profit = max(-prices[i] + helper(i+1, !buy, tr, prices, dp),
                        0 + helper(i+1, buy, tr, prices, dp));
        } else {
            profit = max(prices[i] + helper(i+1, !buy, tr+1, prices, dp),
                        0 + helper(i+1, buy, tr, prices, dp));
        }

        return dp[i][buy][tr] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp (n, vector<vector<int>>(2, vector<int>(2, -1)));

        return helper(0, 1, 0, prices, dp);
    }
};

// buy -> 0 sell krna hai ab
// buy -> 1 buy krna hai ab