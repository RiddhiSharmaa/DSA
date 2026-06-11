class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++){
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i+1; j < n; j++){
                if (j-1 >= 0 && j-1 != i && nums[j] == nums[j-1]) continue;
                long long target1 = target - ((long long)nums[i] + nums[j]);
                int k = j+1;
                int l = n-1;
                while (k < l){
                    long long sum = nums[k] + nums[l];
                    if (sum < target1){
                        k++;
                    } else if (sum > target1){
                        l--;
                    } else{
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                        while (k < n && nums[k] == nums[k-1]) k++;
                        while (l >= 0 && nums[l] == nums[l+1]) l--;
                    }
                }
            }
        }

        return ans;
    }
};