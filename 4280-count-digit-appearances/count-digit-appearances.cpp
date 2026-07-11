class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++){
            int cnt = 0;
            string s = to_string(nums[i]);
            for (int j = 0; j < s.size(); j++){
                if (s[j]-'0' == digit) cnt++;
            }
            ans += cnt;
        }

        return ans;
    }
};