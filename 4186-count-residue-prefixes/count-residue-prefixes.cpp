class Solution {
public:
    int residuePrefixes(string s) {
        unordered_set<char>st;
        int cnt = 0;

        for (int i = 0; i < s.size(); i++){
            st.insert(s[i]);
            if ((i + 1) % 3 == st.size()){
                cnt++;
            }
            if (st.size() >= 3) {
                break; // once 3 distinct char have been found, abive conditon will 
                // never match because mod 3 is always 0, 1 or 2
            }
        }

        return cnt;
    }
    // int residuePrefixes(string s) {
    //     int freq[26] = {0};
    //     string prefix = "";
    //     int dist = 0;
    //     int cnt = 0;

    //     for (int i = 0; i < s.size(); i++){
    //         prefix += s[i];
    //         if (freq[s[i] -'a'] == 0) dist++;
    //         freq[s[i] - 'a']++;
    //         if (prefix.length()%3 == dist) cnt++;
    //     }

    //     return cnt;
    // }
};