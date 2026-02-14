class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int len = 0;
        stack<int>st;

        for (int i = 0; i < s.size(); i++){
            if (!st.empty() && st.top() != s[i]){
                st.pop();
                continue;
            }
            st.push(s[i]);
        }

        return st.size();
    }
};