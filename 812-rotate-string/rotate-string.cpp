class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        if (n != goal.size()) return false;
        string str = s + s;

        if (str.find(goal) != string::npos) return true;

        return false;
    }
};