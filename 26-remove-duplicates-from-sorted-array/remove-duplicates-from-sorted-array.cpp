class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        
        for (int i = 1; i < n; i++){
            if (nums[left] < nums[i]){
                swap(nums[i], nums[left+1]);
                left++;
            }
        }

        return left+1;
    }
};