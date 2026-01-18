class Solution {
public:
    int findMin(vector<int>& nums) {
        int minAns = INT_MAX;
        int low = 0, high = nums.size() - 1;

        while (low <= high){
            int mid = low + (high - low)/2;

            if (nums[low] <= nums[mid]){
                minAns = min(minAns, nums[low]);
                low = mid + 1;
            } else if (nums[mid] <= nums[high]){
                minAns = min(minAns, nums[mid]);
                high = mid - 1;
            }
        }

        return minAns;
    }
};