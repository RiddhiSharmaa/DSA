class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp (n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        // not needed since base case also return 0, and dp is already initialised with 
        // zero
        // for (int i = 0; i <= n; i++){
        //     for (int j = 0; j < 2; j++){
        //         dp[i][j][0] = 0;
        //     }
        // }

        // for (int j = 0; j < 2; j++){
        //     for (int tr = 0; tr <= 2; tr++){
        //         dp[n][j][tr] = 0;
        //     }
        // }
        
        for (int i = n-1; i >= 0; i--){
            for (int j = 0; j < 2; j++){
                for (int tr = 1; tr >= 0; tr--){
                    int profit = 0;
                    if (j == 1){
                        profit = max(-prices[i] + dp[i+1][!j][tr],
                                    0 + dp[i+1][j][tr]);
                    } else {
                        profit = max(prices[i] + dp[i+1][!j][tr+1],
                                    0 + dp[i+1][j][tr]);
                    }
                    dp[i][j][tr] = profit;
                }
            }
        }

        return dp[0][1][0];
    }

    // int helper(int i, int buy, int tr, vector<int>& prices, 
    // vector<vector<vector<int>>>& dp){
    //     if (tr >= 2) return 0;
    //     if (i >= prices.size()) return 0;
    //     if (dp[i][buy][tr] != -1) return dp[i][buy][tr];

    //     int profit = 0;
    //     if (buy == 1){
    //         profit = max(-prices[i] + helper(i+1, !buy, tr, prices, dp),
    //                     0 + helper(i+1, buy, tr, prices, dp));
    //     } else {
    //         profit = max(prices[i] + helper(i+1, !buy, tr+1, prices, dp),
    //                     0 + helper(i+1, buy, tr, prices, dp));
    //     }

    //     return dp[i][buy][tr] = profit;
    // }
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<vector<int>>>dp (n, vector<vector<int>>(2, vector<int>(2, -1)));

    //     return helper(0, 1, 0, prices, dp);
    // }
};

// buy -> 0 sell krna hai ab
// buy -> 1 buy krna hai ab