class Solution {
public:
    using ll = long double;
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        ll sum = 0;
        ll prod = 1;
        int ans = -1;

        for (int i = 0; i < n-1; i++){
            sum += nums[i];
        }

        for (int i = n-1; i >= 0; i--){
            if (prod > sum) return ans;
            if (sum == prod) return i;
            if (i-1 > 0) sum -= nums[i-1];
            if (i-1 > 0) prod *= nums[i];
        }

        return -1;
    }
};