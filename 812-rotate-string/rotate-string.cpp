class Solution {
public:
    string rotateString(string s, int k){
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin()+k);
        reverse(s.begin()+k, s.end());

        string str = s;

        return str;
    }
    bool rotateString(string s, string goal) {
        int n = s.size();
        for (int k = 0; k < n; k++){
            string rotated = rotateString(s, k);
            if (rotated == goal) return true;
        }

        return false;
    }
};