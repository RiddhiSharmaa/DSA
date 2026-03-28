class Solution {
public:
    void helper(int open, int close, string s, vector<string>& ans){
        if (open == close && open == 0){
            ans.push_back(s);
            return;
        }

        if (open == close){
            s += '(';
            helper(open-1, close, s, ans);
        } else if (open == 0){
            s += ')';
            helper(open, close-1, s, ans);
        } else {
            s += '(';
            helper(open-1, close, s, ans);
            s.pop_back();
            s += ')';
            helper(open, close-1, s, ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        helper(n, n, "", ans);

        return ans;
    }
};