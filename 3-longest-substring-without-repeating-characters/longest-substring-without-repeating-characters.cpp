class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        queue<char>q;
        unordered_map<char, int>mpp;
        int ans = 0;

        for (int i = 0; i < n; i++){
            q.push(s[i]);
            mpp[s[i]]++;
            while (mpp[s[i]] > 1){
                while (!q.empty() && q.front() != s[i]){
                    mpp[q.front()]--;
                    q.pop();
                }
                if (!q.empty() && q.front() == s[i]){
                    mpp[q.front()]--;
                    q.pop();
                }
            } 
            ans = max(ans, (int)q.size());
        }

        return ans;
    }
};