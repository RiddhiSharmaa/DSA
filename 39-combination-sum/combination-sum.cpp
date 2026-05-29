class Solution {
public:
    void helper(int i, int target, vector<int>& temp, vector<int>& candidates, vector<vector<int>>& ans){
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (i >= candidates.size() || target < 0) return;

        temp.push_back(candidates[i]);
        helper(i, target - candidates[i], temp, candidates, ans);
        temp.pop_back();
        helper(i+1, target, temp, candidates, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>>ans;
        vector<int>temp;
        helper(0, target, temp, candidates, ans);

        return ans;
    }
};