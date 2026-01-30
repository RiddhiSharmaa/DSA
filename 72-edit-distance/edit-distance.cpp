class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int>>dp(n1+1, vector<int>(n2+1, -1));

        for (int i = 0; i <= n1; i++){
            dp[i][n2] = n1 - i;
        }

        for (int j = 0; j <= n2; j++){
            dp[n1][j] = n2 - j;
        }

        for (int i = n1-1; i >= 0; i--){
            for (int j = n2-1; j >= 0; j--){
                if (word1[i] == word2[j]){
                    dp[i][j] = dp[i+1][j+1];
                } else {
                    dp[i][j] = min({1 + dp[i][j+1],
                    1 + dp[i+1][j], 
                    1 + dp[i+1][j+1]});
                }
            }
        }

        return dp[0][0];
    }

    // int helper(int i, int j, string &word1, string &word2, vector<vector<int>>& dp){
    //     if (i >= word1.size()) return word2.size() - j;
    //     if (j >= word2.size()) return word1.size() - i;

    //     if (dp[i][j] != -1) return dp[i][j];

    //     int ans = 0;
    //     if (word1[i] == word2[j]){
    //         ans = helper(i+1, j+1, word1, word2, dp);
    //     } else {
    //         ans = min({1 + helper(i, j+1, word1, word2, dp),
    //         1 + helper(i+1, j, word1, word2, dp), 
    //         1 + helper(i+1, j+1, word1, word2, dp)});
    //     }

    //     return dp[i][j] = ans;
    // }
    // int minDistance(string word1, string word2) {
    //     int n1 = word1.size(), n2 = word2.size();
    //     vector<vector<int>>dp(n1, vector<int>(n2, -1));

    //     return helper(0, 0, word1, word2, dp);
    // }
};