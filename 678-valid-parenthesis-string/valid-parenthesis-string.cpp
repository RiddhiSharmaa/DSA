class Solution {
public:
    bool check(int i, int cnt, string& s, vector<vector<int>>& dp){
        if (cnt < 0) return false;
        if (i >= s.size()) return (cnt == 0);
        if (dp[i][cnt] != -1) return dp[i][cnt];
        
        bool ans = false;
        if (s[i] == '('){
            ans = check(i+1, cnt+1, s, dp);
        } else if (s[i] == ')'){
            ans = check(i+1, cnt-1, s, dp);
        } else {
            ans = (check(i+1, cnt+1, s, dp) || check(i+1, cnt-1, s, dp) || 
            check(i+1, cnt, s, dp));
        }

        return dp[i][cnt] = ans;
    }
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return check(0, 0, s, dp);
    }
};