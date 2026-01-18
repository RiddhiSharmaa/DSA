class Solution {
public:
    int helper(int low, int high, vector<int>nums, int target){
        while(low <= high){
            int mid = low + (high - low)/2;

            if (nums[mid] == target) return mid;
            if (nums[low] <= nums[mid]){
                if (nums[low] <= target && target <= nums[mid]){
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else if (nums[mid] <= nums[high]){
                if (nums[mid] <= target && target <= nums[high]){
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return helper(0, n-1, nums, target); 
    }
};