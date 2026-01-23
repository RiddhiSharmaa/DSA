class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n+1, -1);

        dp[n] = 1;

        for (int i = n-1; i >= 0; i--){
            int single = dp[i+1];
            int doubleL = 0;
            if (s[i] == '0') {
                dp[i] = 0;
                continue;
            }
            if (i+1 < s.size() && 
            ((s[i] - '0' == 2 && s[i+1] - '0' <= 6) || (s[i] - '0' == 1))) {
                doubleL = dp[i+2];
            }

            dp[i] = single + doubleL;
        }

        return dp[0];
    }

    // int helper(int i, string& s, vector<int>& dp){
    //     if (i >= s.size()) return 1;
    //     if (s[i] == '0') return dp[i] = 0;
    //     if (dp[i] != -1) return dp[i];
        
    //     int single = helper(i+1, s, dp);
    //     int doubleL = 0;
    //     if (i+1 < s.size() && 
    //     ((s[i] - '0' == 2 && s[i+1] - '0' <= 6) || (s[i] - '0' == 1))) {
    //         doubleL = helper(i+2, s, dp);
    //     }

    //     return dp[i] = single + doubleL;
    // }

    // int numDecodings(string s) {
    //     int n = s.size();
    //     vector<int>dp(n, -1);

    //     helper(0, s, dp);

    //     return dp[0];
    // }
};