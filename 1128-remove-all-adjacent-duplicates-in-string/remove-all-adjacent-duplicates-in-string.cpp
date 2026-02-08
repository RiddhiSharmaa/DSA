class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        stack<char>st;
        bool popped = false;

        for (char c : s){
            while (!st.empty() && c == st.top()){
                st.pop();
                popped = true;
            }

            if (popped) {
                popped = false;
                continue;
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