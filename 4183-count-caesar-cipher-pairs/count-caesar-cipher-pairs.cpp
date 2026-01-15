class Solution {
public:
    long long countPairs(vector<string>& words) {
        long long ans = 0;
        unordered_map<string, long long>mpp;

        for (int i = 0; i < words.size(); i++){
            string s = words[i];
            string key = "";
            for (int j = 0; j < s.size(); j++){
                int num = (s[j] - s[0] + 26) % 26;
                char c = num + 'a';
                key += c;
                
            }
            mpp[key]++;
        }

        for (auto& [key, freq] : mpp){
            long long n = freq;
            n--;
            ans += (n * (n+1))/2;
        }

        return ans;
    }
    // long long countPairs(vector<string>& words) {
    //     long long ans = 0;
    //     for (int i = 0; i < words.size(); i++){
    //         string s = words[i];
    //         for (int j = i+1; j < words.size(); j++){
    //             string t = words[j];
    //             if (s == t){
    //                 ans++;
    //                 continue;
    //             }
    //             int diff = (t[0] - s[0] + 26) % 26;
    //             bool isSimilar = true;
    //             for (int k = 0; k < s.size(); k++){
    //                 int num = (t[k] - s[k] + 26) % 26;
    //                 if (num != diff) {
    //                     isSimilar = false;
    //                     break;
    //                 }
    //             }

    //             if (isSimilar) ans++;
    //         }
    //     }

    //     return ans;
    // }
};