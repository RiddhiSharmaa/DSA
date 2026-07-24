class Solution {
public:
    int dp[2001];
    bool checkPal(int i, int k, string& str){
        while (i < k){
            if (str[i] != str[k]) return false;
            i++;
            k--;
        }
        return true;
    }
    int minCut(string s) {
        int n = s.size();
        if (n == 1) return 0;
        memset(dp, -1, sizeof(dp));
        dp[n] = 0;

        for (int i = n-1; i >= 0; i--){
            int minAns = INT_MAX;
            int ans1 = 0;
            for (int k = i; k < s.size(); k++){
                if (checkPal(i, k, s)){
                    ans1 = 1 + dp[k+1];
                    minAns = min(ans1, minAns);
                }
            }
            dp[i] = minAns;
        }
        return dp[0]-1;
    }
};