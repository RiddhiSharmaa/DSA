class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int len = 0, curr = 2;

        for (int right = 2; right < nums.size(); right++){
            if (nums[right-1] + nums[right-2] == nums[right]){
                curr++;
            } else {
                curr = 2;
            }
            len = max(len, curr);
        }

        return len;
    }
};