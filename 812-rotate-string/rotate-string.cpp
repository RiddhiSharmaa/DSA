class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        if (n > goal.size()) return false;
        string str = s + s;

        for (int i = 0; i < 2*n; i++){
            if (str.substr(i, n) == goal) return true;
        }

        return false;
    }
};