class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char>mpp, mpp2;

        for (int i = 0; i < s.size(); i++){
            char c = s[i];
            char d = t[i];
            if (mpp.find(c) == mpp.end()){
                mpp[c] = d;
            }
            if (mpp2.find(d) == mpp2.end()){
                mpp2[d] = c;
            }
            if (mpp2[d] != c || d != mpp[c]) return false;
        }

        return true;
    }
};