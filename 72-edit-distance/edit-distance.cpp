class Solution {
public:
    int helper(int i, int j, string &word1, string &word2, vector<vector<int>>& dp){
        if (i >= word1.size()) return word2.size() - j;
        if (j >= word2.size()) return word1.size() - i;

        if (dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        if (word1[i] == word2[j]){
            ans = helper(i+1, j+1, word1, word2, dp);
        } else {
            ans = min({1 + helper(i, j+1, word1, word2, dp),
            1 + helper(i+1, j, word1, word2, dp),
            1 + helper(i+1, j+1, word1, word2, dp)});
        }
        
        return dp[i][j] = ans;
    }

    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int>>dp(n1, vector<int>(n2, -1));

        return helper(0, 0, word1, word2, dp);
    }
};