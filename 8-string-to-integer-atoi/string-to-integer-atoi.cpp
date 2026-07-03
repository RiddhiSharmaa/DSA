class Solution {
public:
    int myAtoi(string s) {
        int n = s.size(), i = 0;
        bool pos = true;
        long long ans = 0;

        while (i < n){
            if (s[i] != ' ') break;
            i++;
        }

        if (i == n) return ans;

        if (s[i] == '-') {
            pos = false;
            i++;
        }
        else if (s[i] != '+' && (s[i] < '0' || s[i] > '9')) return (int)ans;
        else if (s[i] == '+') i++;

        while (i < n && isdigit(s[i])){
            ans = ans * 10 + (s[i]-'0');
            if (ans > INT_MAX) break;
            i++;
        }

        if (!pos){
            if (ans > INT_MAX) {
                return INT_MIN;
            }
            else return -ans;
        } 
        if (ans > INT_MAX) return INT_MAX;
        return ans;
    }
};