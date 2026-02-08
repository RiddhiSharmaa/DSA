class Solution {
public:
    string removeStars(string s) {
        string ans = "";
        stack<char>st;

        for (char c : s){
            if (!st.empty() && c == '*'){
                st.pop();
            } else {
                st.push(c);
            }
        }

        while (!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};