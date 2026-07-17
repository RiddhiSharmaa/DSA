class Solution {
public:
    int dp[1001][1001];
    int helper(int i, int j, string& text1, string& text2){
        if (i >= text1.size() || j >= text2.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int take = 0, notTake = 0;
        if (text1[i] == text2[j]){
            take = 1 + helper(i+1, j+1, text1, text2);
        } else {
            notTake = max(helper(i+1, j, text1, text2), helper(i, j+1, text1, text2));
        }
        return dp[i][j] = max(take, notTake);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        memset(dp, -1, sizeof(dp));

        return helper(0, 0, text1, text2);
    }
};