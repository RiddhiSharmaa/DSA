class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n, 1);
        vector<int>prefix(n, 1), suffix(n, 1);

        for (int i = 1; i < n; i++){
            suffix[n-i-1] = suffix[n-i] * nums[n-i];
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        for (int i = 0; i < n; i++){
            ans[i] = prefix[i] * suffix[i];
        }

        return ans;
    }
};