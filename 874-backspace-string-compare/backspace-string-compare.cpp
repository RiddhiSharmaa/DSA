class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<int>s1, s2;

        for (int i = 0; i < s.size(); i++){
            if (s[i] == '#'){
                if (!s1.empty()){
                    s1.pop();
                }
            } else{
                s1.push(s[i]);
            }
        }

        for (int i = 0; i < t.size(); i++){
            if (t[i] == '#'){
                if (!s2.empty()){
                    s2.pop();
                }
            } else{
                s2.push(t[i]);
            }
        }

        string str1 = "", str2 = "";
        while (!s1.empty()){
            str1 += s1.top();
            s1.pop();
        }

        while (!s2.empty()){
            str2 += s2.top();
            s2.pop();
        }

        return str1 == str2;
    }
};