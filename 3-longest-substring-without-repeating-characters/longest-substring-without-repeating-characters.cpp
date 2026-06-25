class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int>mpp;
        int left = 0, ans = 0;

        for (int right = 0; right < n; right++){
            while (mpp[s[right]] != 0){
                mpp[s[left]]--;
                left++;
            }
            mpp[s[right]]++;
            ans = max(ans, right-left+1);
        }

        return ans;
    }
};