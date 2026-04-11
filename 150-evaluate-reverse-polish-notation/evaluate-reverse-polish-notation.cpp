class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<string>st;

        for (int i = 0; i < n; i++){
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || 
            tokens[i] == "/"){
                int a = stoi(st.top());
                st.pop();
                int b = stoi(st.top());
                st.pop();
                int c = 1;
                if (tokens[i] == "+") c = b + a;
                else if (tokens[i] == "-") c = b - a;
                else if (tokens[i] == "*") c = b * a;
                else c = b / a;
                st.push(to_string(c));
            } else {
                st.push(tokens[i]);
            }
        }

        return stoi(st.top());
    }
};