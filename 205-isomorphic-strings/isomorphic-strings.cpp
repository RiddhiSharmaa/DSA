class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int mpp1[256];
        int mpp2[256];
        memset(mpp1, -1, sizeof(mpp1));
        memset(mpp2, -1, sizeof(mpp2));

        for (int i = 0; i < s.size(); i++){
            char c = s[i];
            char d = t[i];
            if (mpp1[c] == -1){
                mpp1[c] = d;
            }
            if (mpp2[d] == -1){
                mpp2[d] = c;
            }
            if (mpp2[d] != c || mpp1[c] != d) return false;
        }

        return true;
    }
};