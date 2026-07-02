class Solution {
public:
    int start = 0, end = 0;
    bool check(int i, int j, string& s, vector<vector<int>>& dp){
        if (i >= j) return true;
        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == s[j] && check(i+1, j-1, s, dp)){
            if ((j-i+1) > (end-start+1)){
                start = i;
                end = j;
            }
            return dp[i][j] = true;
        }

        return dp[i][j] = false;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));

        for (int i = 0; i < n; i++){
            for (int j = i; j < n; j++){
                check(i, j, s, dp);
            }
        }

        string ans = s.substr(start, end-start+1);
        return ans;
    }
};