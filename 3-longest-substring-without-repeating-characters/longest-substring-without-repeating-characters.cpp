class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLen = 0;
        int left = 0;
        unordered_map<char, int>mpp;

        for (int right = 0; right < n; right++){
            while (mpp[s[right]] != 0){
                mpp[s[left]]--;
                left++;
            }
            mpp[s[right]]++;
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};