class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++){
            if (i > 0 && nums[i] == nums[i-1]) continue;
            ans++;
        }

        int k = 1;
        for (int i = 1; i < n; i++){
            if (k < ans && i > 0 && nums[i] != nums[k-1]){
                nums[k] = nums[i];
                k++;
            }
            if (k >= ans) break;
        }
        

        return ans;
    }
};