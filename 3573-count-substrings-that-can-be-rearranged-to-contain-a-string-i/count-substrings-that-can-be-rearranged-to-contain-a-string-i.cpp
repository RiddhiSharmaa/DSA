class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        int n = word1.size();
        long long cnt = 0, left = 0;
        int freq[26] = {0};
        int freq2[26] = {0};

        for (char c : word2){
            freq2[c - 'a']++;
        }

        long long reqd = word2.size();

        for (long long right = 0; right < word1.size(); right++){
            freq[word1[right] -'a']++;

            if (freq[word1[right] -'a'] <= freq2[word1[right] -'a']){
                reqd--;
            }

            while (reqd == 0){
                cnt += (n - right);
                if (freq[word1[left] -'a'] <= freq2[word1[left] -'a']){
                    reqd++;
                }
                freq[word1[left] - 'a']--;
                left++;
            }
        }

        return cnt;
    }
};