class Solution {
public:
    int cnt = 0;
    void merge(int low, int mid, int high, vector<int>& nums){
        vector<int>temp;
        int left = low;
        int right = mid+1;

        while (left <= mid && right <= high){
            if (nums[left] <= nums[right]){
                temp.push_back(nums[left]);
                left++;
            } else {
                temp.push_back(nums[right]);
                right++;
            }
        }

        while (left <= mid){
            temp.push_back(nums[left]);
            left++;
        }

        while (right <= high){
            temp.push_back(nums[right]);
            right++;
        }

        for (int i = 0; i < temp.size(); i++){
            nums[i+low] = temp[i];
        }
    }

    void countPairs(int low, int mid, int high, vector<int>& nums){
        int left = low;
        int right = mid+1;

        while (left <= mid && right <= high){
            if (nums[left] > 2 * 1LL * nums[right]){
                cnt += (mid - left + 1);
                right++;
            } else {
                left++;
            }
        }
    }

    void divide(int low, int high, vector<int>& nums){
        if (low >= high) return;

        int mid = low + (high - low)/2;
        divide(low, mid, nums);
        divide(mid+1, high, nums);
        countPairs(low, mid, high, nums);

        merge(low, mid, high, nums);
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        divide(0, n-1, nums);
        return cnt;
    }
};