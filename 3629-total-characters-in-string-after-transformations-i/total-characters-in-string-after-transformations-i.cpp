class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        long long len = 0;
        long long MOD = 1e9 + 7;
        vector<int>freq(26, 0);

        for (int i = 0; i < s.size(); i++){
            freq[s[i]-'a']++;
        }

        while (t--){
            int zCnt = freq[25];
            for (int i = 25; i > 0; i--){
                freq[i] = freq[i-1];
                freq[i-1] = 0;
            }
            if (zCnt > 0){
                freq[0] += (zCnt % MOD);
                freq[1] += (zCnt % MOD);
            }
        }

        for (int i = 0; i < 26; i++){
            len += freq[i];
        }

        return len % MOD;
    }
};