class Solution {
public:
    void helper(int i, vector<int>& temp, vector<int>& nums, vector<int>& visited, 
    set<vector<int>>& ans){
        if (i == nums.size()){
            ans.insert(temp);
            return;
        }
        if (i > nums.size()) return;

        for (int l = 0; l < nums.size(); l++){
            if (visited[l]) continue;

            visited[l] = 1;
            temp.push_back(nums[l]);
            helper(i+1, temp, nums, visited, ans);

            temp.pop_back();
            visited[l] = 0;
        }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>>ans;
        vector<int>temp;
        vector<int>visited(n, 0);
        
        helper(0, temp, nums, visited, ans);

        vector<vector<int>>ans2(ans.begin(), ans.end());

        return ans2;
    }
};