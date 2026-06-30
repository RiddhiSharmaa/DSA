class Solution {
public:
    string reverseWords(string s) {
        while (true){
            if (s[s.size()-1] == ' ') s.pop_back();
            else break;
        }
        reverse(s.begin(), s.end());
        while (true){
            if (s[s.size()-1] == ' ') s.pop_back();
            else break;
        }
        string w = "";
        string ans = "";

        for (int i = 0; i < s.size(); i++){
            if (s[i] == ' '){
                reverse(w.begin(), w.end());
                ans += w;
                if (i > 0 && s[i-1] != ' ') ans += ' ';
                w = "";
                continue;
            }
            w += s[i];
        }

        reverse(w.begin(), w.end());
        ans += w;
        return ans;
    }
};