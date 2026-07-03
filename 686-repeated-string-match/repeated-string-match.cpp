class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        if (b == "") return 0;
        if (a == b) return 1;
        int ans = 1;
        string s = a;

        while (a.size() < b.size()){
            a += s;
            ans++;
        }

        if (a.find(b) != string::npos) return ans;
        a += s;
        if (a.find(b) != string::npos) return ans+1;
        
        if (a.find(b) == string::npos) return -1;

        return ans;
    }
};