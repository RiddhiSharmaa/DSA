class Solution {
public:
    void helper(int i, int target, vector<int>& candidates, vector<int>& temp, 
    vector<vector<int>>& ans){
        if (target == 0){
            ans.push_back(temp);
            return;
        }
        if (i >= candidates.size() || target < 0) return;

        temp.push_back(candidates[i]);
        helper(i, target - candidates[i], candidates, temp, ans);
        temp.pop_back();
        helper(i+1, target, candidates, temp, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        helper(0, target, candidates, temp, ans);
        return ans;
    }
};