class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0;
        string ans = s;
        int left = 0;

        for (int i = 0; i < s.size(); i++){
            if (s[i] == '('){
                cnt++;
            } else {
                cnt--;
            }
            if (cnt == 0){
                ans[i] = '#';
                ans[left] = '#';
                left = i+1;
            }
        }

        string str = "";

        for (char c : ans){
            if (c != '#'){
                str += c;
            }
        }

        return str;
    }
};