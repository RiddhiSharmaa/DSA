class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        sort(nums.begin(), nums.end());
        int len = 1, maxLen = 1;

        for (int i = 1; i < n; i++){
            if (nums[i] == nums[i-1]) continue;
            if (nums[i] == nums[i-1]+1){
                len++;
            } else {
                len = 1;
            }
            maxLen = max(len, maxLen);
        }

        return maxLen;
    }
};