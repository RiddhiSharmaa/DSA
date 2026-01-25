class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>pos;
        for (int i = 0; i < n; i++){
            if (nums[i] >= 0) pos.push_back(nums[i]);
        }

        if (pos.size() == 0) return nums;

        int m = pos.size();
        k %= m;
        reverse(pos.begin(), pos.end());
        reverse(pos.begin(), pos.begin() + (m - k));
        reverse(pos.begin() + (m - k), pos.end());

        // vector<int>copy = pos;
        // int m = pos.size();
        // k %= m;
        // for (int i = 0;i < pos.size(); i++){
        //     pos[(i+m-k)%m] = copy[i];
        // }

        int j = 0;
        for (int i = 0; i < n; i++){
            if (j < m && nums[i] >= 0) {
                nums[i] = pos[j];
                j++;
            }
        }

        return nums;
    }
};