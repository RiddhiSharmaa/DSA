class Solution {
public:
    bool isValid(string s) {
        stack<char>st;

        for (int i = 0; i < s.size(); i++){
            if (st.empty() && (s[i] == ')' || s[i] == ']' || s[i] == '}')){
                return false;
            }
            if (s[i] == ')'){
                if (!st.empty() && st.top() != '(') return false;
                else if (!st.empty()) st.pop();
                continue;
            } else if (s[i] == ']'){
                if (!st.empty() && st.top() != '[') return false;
                else if (!st.empty()) st.pop();
                continue;
            } else if (s[i] == '}'){
                if (!st.empty() && st.top() != '{') return false;
                else if (!st.empty()) st.pop();
                continue;
            } 
            st.push(s[i]);
        }

        return st.empty();
    }
};