class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>vec1(n, 1), vec2(n, 1);
        vector<int>ans(n, 1);

        vec1[0] = nums[0];
        vec2[n-1] = nums[n-1];

        for (int i = 1; i < n; i++){
            vec1[i] = vec1[i-1] * nums[i];
        }

        for (int i = n-2; i >= 0; i--){
            vec2[i] = vec2[i+1] * nums[i];
        }

        ans[0] = vec2[1];
        ans[n-1] = vec1[n-2];
        for (int i = 1; i < n-1; i++){
            ans[i] = vec1[i-1] * vec2[i+1];
        }

        return ans;
    }
};