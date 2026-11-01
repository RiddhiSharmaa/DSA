class Solution {
public:
    string reverseWords(string s) {
        int startIdx = 0;
        
        for (int i = 0; i < s.size(); i++){
            if (s[i] == ' '){
                reverse(s.begin() + startIdx, s.begin() + i);
                startIdx = i+1;
            }
        }

        reverse(s.begin() + startIdx, s.end());
        return s;
    }
};