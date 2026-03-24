class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;

        for (int i = 0; i < n; i++){
            while (nums[i] >= 1 && nums[i] <= n && nums[i] != nums[nums[i]-1]){
                swap(nums[i], nums[nums[i]-1]);
            }
            if (nums[i] >= 1 && nums[i] == nums[nums[i]-1] && i != nums[i]-1) {
                ans.push_back(nums[i]);
                nums[i] = -1;    
            }
        }

        return ans;
    }
};