class Solution {
public:
    void helper(int i, string s, string& digits, vector<string>& ans, 
    unordered_map<char, string>& mpp){
        if (s.size() == digits.size()){
            ans.push_back(s);
            return;
        }

        for (char c : mpp[digits[i]]){
            s += c;
            helper(i+1, s, digits, ans, mpp);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
       unordered_map<char, string> mpp = {{'2', "abc"},{'3', "def"},{'4', "ghi"},
       {'5', "jkl"},{'6', "mno"},{'7', "pqrs"},{'8', "tuv"},{'9', "wxyz"}};

        vector<string>ans;
        helper(0, "", digits, ans, mpp);

        return ans;
    }
};