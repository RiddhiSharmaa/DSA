class Solution {
public:
    vector<vector<int>>ans;
    void helper(int i, int sum, vector<int> temp, vector<int>& candidates, int &target){
        // base case
        if (i >= candidates.size()) return;
        if (sum > target) return;
        if (sum == target){
            ans.push_back(temp);
            return;
        }
        //pick
        temp.push_back(candidates[i]);
        helper(i, sum + candidates[i], temp, candidates, target);

        temp.pop_back();
        helper(i+1, sum, temp, candidates, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        helper(0, 0, temp, candidates, target);

        return ans;
    }
};