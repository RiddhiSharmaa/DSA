class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;

        for (string& s : tokens){
            if (s == "+" || s == "/" || s == "*" || s == "-"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int num = 0;
                if (s == "+"){
                    num = a + b;
                } else if (s == "-"){
                    num = a - b;
                } else if (s == "*"){
                    num = a * b;
                } else if (s == "/"){
                    num = a / b;
                }
                st.push(num);
            } else{
                st.push(stoi(s));
            }
        }

        return st.top();
    }
};