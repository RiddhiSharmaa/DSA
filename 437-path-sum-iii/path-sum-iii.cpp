/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* root, long long currSum, int target, 
    unordered_map<long long, int>& prefix, int& ans){
        if (!root) return;

        currSum += root -> val;
        if (prefix.find(currSum - target) != prefix.end()){
            ans += prefix[currSum - target];
        } 
        prefix[currSum]++;

        helper(root -> left, currSum, target, prefix, ans);
        helper(root -> right, currSum, target, prefix, ans);
        prefix[currSum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int>prefix;
        prefix[0] = 1;
        int ans = 0;

        helper(root, 0, targetSum, prefix, ans);

        return ans;
    }
};