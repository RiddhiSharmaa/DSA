class Solution {
public:
    void helper(int i, int target, vector<int>& temp, vector<int>& nums, vector<vector<int>>& ans){
        if (target == 0){
            ans.push_back(temp);
            return;
        }
        if (i >= nums.size()) return;
        if (target < 0) return;

        for (int j = i; j < nums.size(); j++){
            if (j > i && nums[j] == nums[j-1]) continue;
            
            temp.push_back(nums[j]);
            helper(j+1, target - nums[j], temp, nums, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>temp;
        helper(0, target, temp, candidates, ans);

        return ans;
    }
};