class Solution {
public:
    void helper(int idx, vector<int>& temp, vector<int>& visited, vector<int>& nums, vector<vector<int>>& ans){
        if (temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++){
            if (i > 0 && nums[i] == nums[i-1] && !visited[i-1]) continue;
            if (visited[i]) continue;
            visited[i] = 1;
            temp.push_back(nums[i]);
            helper(i+1, temp, visited, nums, ans);
            visited[i] = 0;
            temp.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        vector<int>visited(nums.size(), 0);
        helper(0, temp, visited, nums, ans);
        return ans;
    }
};