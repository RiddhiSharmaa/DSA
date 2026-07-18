class Solution {
public:
    int dp[501][501];
    int helper(int i, int j, string& word1, string& word2){
        if (j >= word2.size() && i < word1.size()) return word1.size()-i;
        if (i >= word1.size() && j < word2.size()) return word2.size()-j;
        if (i >= word1.size() || j >= word2.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int case1 = 1e9, case2 = 1e9;
        if (word1[i] == word2[j]){
            case1 = helper(i+1, j+1, word1, word2);
        } else {
            case2 = min({(1 + helper(i+1, j, word1, word2)), 
            (1 + helper(i, j+1, word1, word2)), 
            (1 + helper(i+1, j+1, word1, word2))});
        }
        return dp[i][j] = min(case1, case2);
    }
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp));
        return helper(0, 0, word1, word2);
    }
};