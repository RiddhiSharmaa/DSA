class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        vector<string>v;
        string temp = "";
        temp += s[0];
        int maxi = 0;
        int active = 0;

        for (int i = 1; i < n; i++){
            if (s[i] == temp.back()) temp += s[i];
            else {
                v.push_back(temp);
                temp = "";
                temp = s[i];
            }
        }
        if (temp.size() > 0) v.push_back(temp);

        for (int i = 0; i < v.size(); i++){
            if (v[i][0] == '1'){
                if (i >= 1 && i < v.size()-1 && v[i-1][0] == '0' && v[i+1][0] == '0'){
                    int m = v[i+1].size() + v[i-1].size();
                    maxi = max(maxi, m);
                }
                active += v[i].size();
            } 
        }

        return maxi+active;
    }
};