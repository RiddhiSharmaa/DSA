class Solution {
public:
    string reverseWords(string s) {
        string w = "";
        string rev = "";

        for (int i = 0; i < s.size(); i++){
            if (s[i] != ' '){
                w += s[i];
            } else {
                reverse(w.begin(), w.end());
                rev += w;
                rev += ' ';
                w = "";
            }
        }

        reverse(w.begin(), w.end());
        rev += w;
        return rev;
    }
};