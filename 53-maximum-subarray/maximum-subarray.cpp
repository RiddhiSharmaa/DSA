class Solution {
public:
    using ll = long long;
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        ll sum = 0, maxSum = LLONG_MIN;

        for (int i = 0; i < n; i++){
            sum += nums[i];
            maxSum = max(maxSum, sum);
            
            if (sum < 0){
                sum = 0;
            }
        }

        return (int)maxSum;
    }
};