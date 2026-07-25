class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char>mpp, mpp2;

        for (int i = 0; i < s.size(); i++){
            char c = s[i];
            char d = t[i];
            if (mpp.find(c) == mpp.end() && mpp2.find(d) == mpp2.end()){
                mpp[c] = d;
                mpp2[d] = c;
            } else if (mpp2.find(d) != mpp2.end()){
                if (mpp2[d] != c) return false;
            } else {
                if (d != mpp[c]) return false;
            }
        }

        return true;
    }
};