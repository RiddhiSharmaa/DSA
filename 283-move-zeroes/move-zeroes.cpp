class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 1;
        
        while (left < n && right < n){
            if (nums[left] == 0 && nums[right] != 0){
                swap(nums[left], nums[right]);
            }
            if (nums[left] != 0){
                left++;
            }
            right++;
        }

    }
};