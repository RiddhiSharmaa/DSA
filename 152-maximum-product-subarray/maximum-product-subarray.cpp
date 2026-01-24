class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN, currProd = 1;

        for (int i = 0; i < n; i++){
            if (nums[i] == 0){
                ans = max(ans, 0);
                currProd = 1;
                continue;
            }
            currProd *= nums[i];
            ans = max(ans, currProd);
        }

        currProd = 1;
        for (int i = n-1; i >= 0; i--){
            if (nums[i] == 0){
                ans = max(ans, 0);
                currProd = 1;
                continue;
            }
            currProd *= nums[i];
            ans = max(ans, currProd);
        }

        return ans;
    }
};