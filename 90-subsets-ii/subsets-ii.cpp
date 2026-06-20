class Solution {
public:
    void helper(int i, vector<int>&temp, vector<int>& nums, vector<vector<int>>& ans){
        if (i >= nums.size()) {
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        helper(i+1, temp, nums, ans);

        int idx = i + 1;
        while (idx < nums.size() && nums[idx] == nums[idx-1]) idx++;

        temp.pop_back();
        helper(idx, temp, nums, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        helper(0, temp, nums, ans);
        return ans;
    }
};