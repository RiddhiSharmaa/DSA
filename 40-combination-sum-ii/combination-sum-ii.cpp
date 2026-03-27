class Solution {
public:
    vector<vector<int>>ans;
    void helper(int idx, vector<int>& temp, vector<int>& candidates, int target){
        if (target == 0){
            ans.push_back(temp);
            return;
        }
        if (idx >= candidates.size() || target < 0) return;
        if (candidates[idx] > target) return;

        for (int i = idx; i < candidates.size(); i++){
            if (i > idx && candidates[i] == candidates[i-1]) continue;
            
            temp.push_back(candidates[i]);
            helper(i+1, temp, candidates, target - candidates[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>temp;
        sort(candidates.begin(), candidates.end());
        helper(0, temp, candidates, target);
        
        return ans;
    }
};