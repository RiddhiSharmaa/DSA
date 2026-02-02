class Solution {
public:
    int helper(int i, int j, string &s, string &t, vector<vector<int>>& dp){
        if (i >= s.size() && j < t.size()) return 0;
        if (i >= s.size() && j >= t.size()) return 1;
        if (i < s.size() && j >= t.size()) return 1;

        if (dp[i][j] != -1) return dp[i][j];

        int take = 0;
        if (s[i] == t[j]){
            take = helper(i+1, j+1, s, t, dp);
        } 

        int notTake = helper(i+1, j, s, t, dp);

        return dp[i][j] = take + notTake;
    }

    int numDistinct(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        vector<vector<int>>dp (n1, vector<int>(n2, -1));

        return helper(0, 0, s, t, dp);
    }
};