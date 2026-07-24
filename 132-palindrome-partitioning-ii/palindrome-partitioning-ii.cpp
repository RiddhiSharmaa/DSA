class Solution {
public:
    int dp[2001];
    bool pal[2001][2001];
    int minCut(string s) {
        int n = s.size();
        if (n == 1) return 0;
        memset(dp, -1, sizeof(dp));
        memset(pal, -1, sizeof(pal));

        for (int l = 1; l <= n; l++){
            for (int i = 0; i+l-1 < n; i++){
                int j = i+l-1;
                if (i == j) pal[i][i] = true;
                else if (i+1 == j) pal[i][j] = (s[i] == s[j]);
                else {
                    if (s[i] == s[j] && pal[i+1][j-1]) pal[i][j] = true;
                    else pal[i][j] = false;
                }
            }
        }

        dp[n] = 0;

        for (int i = n-1; i >= 0; i--){
            int minAns = INT_MAX;
            int ans1 = 0;
            for (int k = i; k < s.size(); k++){
                if (pal[i][k]){
                    ans1 = 1 + dp[k+1];
                    minAns = min(ans1, minAns);
                }
            }
            dp[i] = minAns;
        }
        return dp[0]-1;
    }
};