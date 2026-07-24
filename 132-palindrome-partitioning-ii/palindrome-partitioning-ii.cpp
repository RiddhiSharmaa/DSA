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
    int helper(int i, string& s){
        if (i >= s.size()) return 0;
        if (dp[i] != -1) return dp[i];
        int ans1 = 0;
        int minAns = INT_MAX;
        for (int k = i; k < s.size(); k++){
            if (checkPal(i, k, s)){
                ans1 = 1 + helper(k+1, s);
                minAns = min(ans1, minAns);
            }
        }
        return dp[i] = minAns;
    }
    int minCut(string s) {
        if (s.size() == 1) return 0;
        memset(dp, -1, sizeof(dp));
        return helper(0, s)-1;
    }
};