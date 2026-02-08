class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";

        for (char c : s){
            while (!ans.empty() && ans.size() >= 2 && 
            ans.back() == ans[ans.size()-2]){
                ans.pop_back();
                ans.pop_back();
            }

            ans += c;
        }

        while (!ans.empty() && ans.size() >= 2 && 
        ans.back() == ans[ans.size()-2]){
            ans.pop_back();
            ans.pop_back();
        }

        return ans;
    }
};