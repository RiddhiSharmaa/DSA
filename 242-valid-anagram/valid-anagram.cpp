class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int>h1(26, 0);

        for (int i = 0; i < s.size(); i++){
            h1[s[i]-'a']++;
        }

        for (int i = 0; i < t.size(); i++){
            h1[t[i]-'a']--;
            if (h1[t[i]-'a'] < 0) return false;
        }

        for (int i = 0; i < 26; i++){
            if (h1[i] != 0) return false;
        }

        return true;
    }
};