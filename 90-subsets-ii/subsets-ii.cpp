class Solution {
public:
    void helper(int i, vector<int>& nums, vector<int> temp, 
    vector<vector<int>>& ans){
        ans.push_back(temp);
        if (i >= nums.size()) return;

        for (int idx = i; idx < nums.size(); idx++){
            if (idx > i && nums[idx] == nums[idx-1]) continue;
            //pick
            temp.push_back(nums[idx]);
            helper(idx+1, nums, temp, ans);
            //not pick
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(nums.begin(), nums.end());

        helper(0, nums, temp, ans);

        return ans;   
    }
};