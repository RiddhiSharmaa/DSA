class Solution {
public:
    void helper(int i, vector<int>& temp, vector<int>& visited, vector<int>& nums,
    vector<vector<int>>& ans){
        if (i >= nums.size()){
            ans.push_back(temp);
            return;
        }
        
        for (int j = 0; j < nums.size(); j++){
            if (visited[j]) continue;
            visited[j] = 1;
            temp.push_back(nums[j]);
            helper(i+1, temp, visited, nums, ans);
            visited[j] = 0;
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int>temp;
        vector<int>visited(n, 0);

        helper(0, temp, visited, nums, ans);

        return ans;
    }
};