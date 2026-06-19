class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        long long len = 0;
        long long MOD = 1e9 + 7;
        vector<int>v(26, 0);

        for (int i = 0; i < s.size(); i++){
            v[s[i]-'a']++;
        }

        while (t--){
            vector<int>temp(26, 0);
            for (int i = 0; i < 26; i++){
                if (i != 25){
                    temp[i+1] += v[i];
                } else {
                    temp[0] += (v[25] % MOD);
                    temp[1] += (v[25] % MOD);
                }
            }
            v = temp;
        }

        for (int i = 0; i < 26; i++){
            len += v[i];
        }

        return len % MOD;
    }
};