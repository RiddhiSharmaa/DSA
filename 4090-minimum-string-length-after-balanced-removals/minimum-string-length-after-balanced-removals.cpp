class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int len = 0;
        string ans = "";

        for (int i = 0; i < s.size(); i++){
            ans.push_back(s[i]);
            if (ans.size() >= 2 && ans.back() == 'b' && ans[ans.size()-2] == 'a'){
                ans.pop_back();
                ans.pop_back();
            } else if (ans.size() >= 2 && ans.back() == 'a' && ans[ans.size()-2] == 'b'){
                ans.pop_back();
                ans.pop_back();
            }
            
        }

        return ans.size();
    }
};