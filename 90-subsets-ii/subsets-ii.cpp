class Solution {
public:
    void helper(int i, vector<int>& nums, vector<int> temp, set<vector<int>>& ans){
        if (i >= nums.size()) {
            sort(temp.begin(), temp.end());
            ans.insert(temp);
            return;
        }
        //not pick
        helper(i+1, nums, temp, ans);
        //pick
        temp.push_back(nums[i]);
        helper(i+1, nums, temp, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>ans;
        vector<int>temp;
        helper(0, nums, temp, ans);
        vector<vector<int>>v(ans.begin(), ans.end());
        return v;   
    }
};