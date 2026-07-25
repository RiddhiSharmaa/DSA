class Solution {
public:
    bool pal[17][17];
    // int dp[17];
    void helper(int i, vector<string>& temp, string& s, vector<vector<string>>& ans){
        if (i >= s.size()){
            ans.push_back(temp);
            return;
        }

        string str = "";
        for (int k = i; k < s.size(); k++){
            str += s[k];
            if (pal[i][k]){
                temp.push_back(str);
                helper(k+1, temp, s, ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>>ans;
        memset(pal, -1, sizeof(pal));
        // memset(dp, -1, sizeof(dp));

        for (int len = 1; len <= n; len++){
            for (int i = 0; i+len-1 < n; i++){
                int j = i+len-1;
                if (i == j) pal[i][i] = true;
                else if (i+1 == j) pal[i][j] = (s[i] == s[j]);
                else {
                    if (s[i] == s[j] && pal[i+1][j-1]) pal[i][j] = true;
                    else pal[i][j] = false;
                }
            }
        }

        vector<string>temp;
        helper(0, temp, s, ans);
        return ans;
    }
};