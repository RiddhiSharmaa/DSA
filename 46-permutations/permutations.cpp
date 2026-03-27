class Solution {
public:
    void helper(vector<int> temp, vector<int>& nums, vector<bool>& visited, 
    vector<vector<int>>& ans){
        if (temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++){
            if (visited[i]) continue;

            visited[i] = true;
            temp.push_back(nums[i]);
            helper(temp, nums, visited, ans);

            temp.pop_back();
            visited[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int>temp;
        vector<bool>visited(n, 0);
        
        helper(temp, nums, visited, ans);

        return ans;
    }
};