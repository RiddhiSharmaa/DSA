class Solution {
public:
    int n1;
    bool helper(int i, string s, unordered_set<string>& st, vector<int>& dp){
        if (i >= n1) return true;

        if (dp[i] != -1) return dp[i];

        for (int len = 1; len <= s.size(); len++){
            string temp = s.substr(i, len);
            if (st.count(temp) && helper(i+len, s, st, dp)){
                return dp[i] = true;
            }
        }

        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n1 = s.size();
        unordered_set<string>st(wordDict.begin(), wordDict.end());
        vector<int>dp(n1, -1);
        
        return helper(0, s, st, dp);
    }
};