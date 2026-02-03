class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string>st;

        for (string& s : tokens){
            if (s == "+" || s == "/" || s == "*" || s == "-"){
                int b = stoi(st.top());
                st.pop();
                int a = stoi(st.top());
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
                st.push(to_string(num));
            } else{
                st.push(s);
            }
        }

        return stoi(st.top());
    }
};