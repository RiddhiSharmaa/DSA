class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN, currSum = 0;

        for (int i = 0; i < n; i++){
            currSum += nums[i];
            if (ans < currSum) ans = currSum;
            if (currSum < 0) currSum = 0;
        }

        return ans;
    }
};