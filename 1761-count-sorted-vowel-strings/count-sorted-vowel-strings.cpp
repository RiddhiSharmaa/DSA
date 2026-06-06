class Solution {
public:
    int helper(int i, string str, int& n, string& s, vector<vector<int>>& dp){
        if (str.size() == n) return 1;
        if (str.size() > n || i >= s.size()) return 0;
        if (dp[i][str.size()] != -1) return dp[i][str.size()];

        str += s[i];
        int pick = helper(i, str, n, s, dp);
        str.pop_back();
        int notPick = helper(i+1, str, n, s, dp);

        return dp[i][str.size()] = pick + notPick;
    }
    int countVowelStrings(int n) {
        string s = "aeiou";
        int k = s.size();
        vector<vector<int>>dp(k+1, vector<int>(n+1, -1));

        helper(0, "", n, s, dp);

        return dp[0][0];
    }
};