class Solution {
public:
    string reverseWords(string s) {
        stack<char>st;
        int id = 0, j = s.size()-1;
        while (true){
            if (s[id] == ' ') id++;
            else break;
        }
        while (true){
            if (s[j] == ' ') j--;
            else break;
        }
        string w = "";
        string ans = "";

        for (int i = id; i <= j; i++){
            if (s[i] == ' '){
                if (!st.empty() && st.top() != ' ') st.push(s[i]);
                continue;
            }
            st.push(s[i]);
        }

        while (!st.empty()){
            if (st.top() == ' '){
                reverse(w.begin(), w.end());
                ans += w + ' ';
                w = "";
                st.pop();
                continue;
            }
            w += st.top();
            st.pop();
        }
        
        reverse(w.begin(), w.end());
        ans += w;
        return ans;
    }
};