class Solution {
public:
    void merge(int i, int j, int mid, vector<int>& nums){
        int n = nums.size();
        if (n == 1) return;
        vector<int>temp;
        int l = i, m = j, t = mid+1;
        
        while (i <= mid && t <= j){
            if (nums[i] <= nums[t]){
                temp.push_back(nums[i]);
                i++;
            } else if (nums[i] > nums[t]){
                temp.push_back(nums[t]);
                t++;
            }
        }

        while (i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }

        while (t <= j){
            temp.push_back(nums[t]);
            t++;
        }

        int p = 0;
        for (int k = l; k <= j; k++){
            nums[k] = temp[p];
            p++;
        }
    }
    void helper(int i, int j, vector<int>& nums){
        if (i >= j) return;
        int mid = (i + j)/2;

        if (i < j){
            helper(i, mid, nums);
            helper(mid+1, j, nums);
        }

        merge(i, j, mid, nums);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        helper(0, n-1, nums);

        return nums;
    }
};