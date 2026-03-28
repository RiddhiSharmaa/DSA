class Solution {
public:
    void helper(int i, string s, string& digits, vector<string>& ans, 
    vector<string>& mpp){
        if (s.size() == digits.size()){
            ans.push_back(s);
            return;
        }

        for (char c : mpp[digits[i]-'0']){
            s += c;
            helper(i+1, s, digits, ans, mpp);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
       vector<string> mpp = {"", "", "abc", "def" , "ghi", "jkl", "mno", "pqrs", "tuv",
       "wxyz"};

        vector<string>ans;
        helper(0, "", digits, ans, mpp);

        return ans;
    }
};