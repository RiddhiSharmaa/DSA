class Solution {
public:
    using ll = long long;
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        ll sum = 0;

        for (int x : nums){
            sum += x;
        }

        if (sum < target) return 0;

        ll left = 0, right = 0;
        ll currSum = 0, minW = LLONG_MAX;

        while (left <= right && right < n){
            currSum += nums[right];
            while (currSum >= target){
                minW = min(minW, (right-left+1));
                currSum -= nums[left];
                left++;
            }
            right++;
        }

        return (minW == INT_MAX) ? 0 : (int)minW;
    }
};