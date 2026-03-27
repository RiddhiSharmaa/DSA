class Solution {
public:
    vector<vector<int>>ans;
    void helper(int i, vector<int>& temp, vector<int>& candidates, int target){
        if (target == 0){
            ans.push_back(temp);
            return;
        }
        if (i >= candidates.size() || target < 0) return;
        if (candidates[i] > target) return;

        temp.push_back(candidates[i]);
        helper(i, temp, candidates, target - candidates[i]);

        temp.pop_back();
        helper(i+1, temp, candidates, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        sort(candidates.begin(), candidates.end());
        helper(0, temp, candidates, target);

        return ans;
    }
};