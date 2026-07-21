class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        vector<pair<char, int>>v;
        char prev = s[0];
        int tempSize = 1;
        int maxi = 0;
        int active = 0;

        for (int i = 1; i < n; i++){
            if (s[i] == prev) tempSize++;
            else {
                v.push_back({prev, tempSize});
                prev = s[i];
                tempSize = 1;
            }
        }
        if (tempSize) v.push_back({prev, tempSize});

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