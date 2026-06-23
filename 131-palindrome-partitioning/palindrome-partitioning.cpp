class Solution {
public:
    bool palindrome(string& s){
        int n = s.size();
        for (int i = 0; i < n/2; i++){
            if (s[i] != s[n-i-1]) return false;
        }
        return true;
    }
    void helper(int idx, vector<string>& temp, string& s, vector<vector<string>>& ans){
        if (idx == s.size()){
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < s.size(); i++){
            string str = s.substr(idx, i-idx+1);
            if (palindrome(str)){
                temp.push_back(str);
                helper(i+1, temp, s, ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>>ans;
        vector<string>temp;
        helper(0, temp, s, ans);

        return ans;
    }
};