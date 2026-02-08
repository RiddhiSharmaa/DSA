class Solution {
public:
    string removeStars(string s) {
        string ans = "";

        for (char c : s){
            ans += c;

            if (!ans.empty() && ans.back() == '*'){
                ans.pop_back();
                ans.pop_back();
            }
        }

        return ans;
    }
};