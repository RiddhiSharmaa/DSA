class Solution {
public:
    int dp[501][501];
    int helper(int l, int r, vector<int>& piles){
        if (l > r) return 0;

        if (dp[l][r] != -1) return dp[l][r];

        int takeLeft = piles[l] - helper(l+1, r, piles);
        int takeRight = piles[r] - helper(l, r-1, piles);

        return dp[l][r] = max(takeLeft, takeRight);
    }
    bool stoneGame(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        return helper(0, piles.size()-1, piles) > 0;
    }
};