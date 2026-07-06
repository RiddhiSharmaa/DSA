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
    void helper(TreeNode* root, vector<int>& temp, vector<vector<int>>& ans,
    int targetSum){
        if (!root) return;
        if (!root -> left && !root -> right){
            if (targetSum == root -> val) {
                temp.push_back(root -> val);
                ans.push_back(temp);
                temp.pop_back();
                return;
            }
        }
        temp.push_back(root -> val);
        helper(root -> left, temp, ans, targetSum - root -> val);
        helper(root -> right, temp, ans, targetSum - root -> val);
        temp.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return {};
        vector<vector<int>>ans;
        vector<int>temp;
        helper(root, temp, ans, targetSum);
        return ans;
    }
};