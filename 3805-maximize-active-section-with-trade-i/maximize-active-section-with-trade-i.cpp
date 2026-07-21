class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        vector<pair<char, int>>v;
        string temp = "";
        temp += s[0];
        int maxi = 0;
        int active = 0;

        for (int i = 1; i < n; i++){
            if (s[i] == temp.back()) temp += s[i];
            else {
                v.push_back({temp.back(), temp.size()});
                temp.clear();
                temp += s[i];
            }
        }
        if (temp.size() > 0) v.push_back({temp.back(), temp.size()});

        for (int i = 0; i < v.size(); i++){
            if (v[i].first == '1'){
                if (i >= 1 && i < v.size()-1 && v[i-1].first == '0' && 
                v[i+1].first == '0'){
                    int m = v[i+1].second + v[i-1].second;
                    maxi = max(maxi, m);
                }
                active += v[i].second;
            } 
        }

        return maxi+active;
    }
};