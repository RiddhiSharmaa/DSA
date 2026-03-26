class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>vec1(n, 1), vec2(n, 1);
        vector<int>ans(n, 1);

        for (int i = 1; i < n; i++){
            vec1[i] = vec1[i-1] * nums[i-1];
            vec2[n-i-1] = vec2[n-i] * nums[n-i];
        }

        for (int i = 0; i < n; i++){
            ans[i] = vec1[i] * vec2[i];
        }

        return ans;
    }
};