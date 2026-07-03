class Solution {
public:
    int dp[501][501];
    int helper(int left, int right, string& s){
        if (left >= right) return 0;
        if (dp[left][right] != -1) return dp[left][right];

        int ans1 = 0;
        if (s[left] == s[right]){
            ans1 = helper(left+1, right-1, s);
        } else {
            ans1 = min(1 + helper(left, right-1, s), 1 + helper(left+1, right, s));
        }

        return dp[left][right] = ans1;
    }
    int minInsertions(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        return helper(0, n-1, s);
    }
};