class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        stack<int>st;
        int idx = -1;
        int j = 0;

        for (int i = 0; i < n; i++){
            st.push(pushed[i]);
            while (!st.empty() && j < n && st.top() == popped[j]){
                st.pop();
                j++;
            }
        }

        while (!st.empty() && j < n){
            if (j < n && st.top() == popped[j]){
                st.pop();
                
            }
            j++;
        }

        return st.empty();
    }
};