class Solution {
public:
    int dp[101][10001];
    int helper(int e, int f){
        if (e == 1 || f <= 1) return f;
        if (dp[e][f] != -1) return dp[e][f];
        int low = 1, high = f;
        int ans  = INT_MAX;
        while (low <= high){
            int mid = (low+high)/2;
            int left = helper(e-1, mid-1);
            int right = helper(e, f-mid);
            int temp = 1 + max(left, right);
            if (left > right){
                high = mid-1;
            } else {
                low = mid+1;
            }
            ans = min(ans, temp);
        }
        return dp[e][f] = ans;
    }
    int superEggDrop(int k, int n) {
        memset(dp, -1, sizeof(dp));
        return helper(k, n);
    }
};