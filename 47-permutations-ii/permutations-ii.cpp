class Solution {
public:
    void helper(vector<int>& temp, vector<int>& nums, vector<int>& visited, 
    vector<vector<int>>& ans){
        if (temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++){
            if (i > 0 && !visited[i-1] && nums[i] == nums[i-1]) continue;
            if (visited[i]) continue;

            visited[i] = 1;
            temp.push_back(nums[i]);
            helper(temp, nums, visited, ans);

            temp.pop_back();
            visited[i] = 0;
        }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        vector<int>visited(n, 0);
        
        helper(temp, nums, visited, ans);

        return ans;
    }
};