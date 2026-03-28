class Solution {
public:
    bool checkPalindrome(string& k){
        int n = k.size();

        for (int i = 0; i < n/2; i++){
            if (k[i] != k[n-i-1]) return false;
        }

        return true;
    }
    void helper(int i, vector<string>& temp, vector<vector<string>>& ans, string& s){
        if (i >= s.size()){
            ans.push_back(temp);
            return;
        }
        for (int l = i; l < s.size(); l++){
            string str = s.substr(i, l-i+1);
            if (checkPalindrome(str)){
                temp.push_back(str);
                helper(l+1, temp, ans, s);
                temp.pop_back(); //backtrack
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>>ans;
        vector<string>temp;

        helper(0, temp, ans, s);

        return ans;
    }
};