class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        stack<string>st;
        string str = "";
        string ans = "";

        for (int i = 0; i < n; i++){
            if (s[i] != ' '){
                str += s[i];
            } else {
                if (str.size() > 0){
                    st.push(str);
                    str = "";
                }
            }
        }

        if (str.size() > 0){
            st.push(str);
        }

        while (!st.empty()){
            if (st.size() != 1) ans += st.top() + ' ';
            else ans += st.top();
            st.pop();
        }
        
        return ans;
    }
};