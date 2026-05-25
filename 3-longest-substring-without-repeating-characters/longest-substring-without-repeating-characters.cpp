class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        queue<char>q;
        int maxLen = 0;
        unordered_map<char, int>mpp;

        for (int i = 0; i < n; i++){
            if (mpp[s[i]] != 0){
                while (!q.empty() && q.front() != s[i]){
                    mpp[q.front()]--;
                    q.pop();
                }
                if (!q.empty()) {
                    mpp[q.front()]--;
                    q.pop();
                }
            }
            mpp[s[i]]++;
            q.push(s[i]);
            maxLen = max(maxLen, (int)q.size());
        }

        return maxLen;
    }
};