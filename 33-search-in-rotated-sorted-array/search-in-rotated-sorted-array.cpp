class Solution {
public:
    int binary_search(int low, int high, vector<int>& nums, int target){
        while (low <= high){
            int mid = low + (high-low)/2;
            if (nums[mid] == target){
                return mid;
            } else if (nums[mid] < target){
                low = mid+1;
            } else if (nums[mid] > target){
                high = mid-1;
            }
        }

        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        int ans = -1;

        while (low <= high){
            int mid = low + (high - low)/2;
            if (nums[mid] == target){
                return mid;
            } else if (nums[low] <= nums[mid]){
                if (target >= nums[low] && target <= nums[mid]){
                    return binary_search(low, mid, nums, target);
                } else {
                    low = mid+1;
                }
            } else {
                if (target >= nums[mid] && target <=  nums[high]){
                    return binary_search(mid, high, nums, target);
                } else {
                    high = mid-1;
                }
            } 
        }

        return ans;
    }
};