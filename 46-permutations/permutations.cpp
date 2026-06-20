class Solution {
public:
    void helper(vector<int>& visited, vector<int>& temp, vector<int>& nums, vector<vector<int>>& ans){
        if (temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++){
            if (visited[i]) continue;
            visited[i] = 1;
            temp.push_back(nums[i]);
            helper(visited, temp, nums, ans);
            visited[i] = 0;
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        vector<int>visited(nums.size(), 0);
        helper(visited, temp, nums, ans);
        return ans;
    }
};