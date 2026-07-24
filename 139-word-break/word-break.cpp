class Solution {
public:
    int dp[301];
    bool helper(int i, string& s, unordered_set<string>&st){
        if (i >= s.size()) return true;
        if (dp[i] != -1) return dp[i];
        for (int k = i; k < s.size(); k++){
            string str = s.substr(i, k-i+1);
            if (st.find(str) != st.end()){
                if (helper(k+1, s, st)) return dp[i] = true;
            }
        }
        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp, -1, sizeof(dp));
        unordered_set<string>st(wordDict.begin(), wordDict.end());
        return helper(0, s, st);
    }
};