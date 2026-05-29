class Solution {
public:
    void helper(int i, vector<int>& temp, vector<int>& visited, vector<int>& nums, vector<vector<int>>& ans){
        if (temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }

        for (int j = 0; j < nums.size(); j++){
            if (j > 0 && nums[j] == nums[j-1] && !visited[j-1]) continue;
            if (visited[j]) continue;
            visited[j] = 1;
            temp.push_back(nums[j]);
            helper(j+1, temp, visited, nums, ans);
            temp.pop_back();
            visited[j] = 0;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        vector<int>visited(n, 0);
        helper(0, temp, visited, nums, ans);

        return ans;
    }
};