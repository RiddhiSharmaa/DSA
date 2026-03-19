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
    void helper(TreeNode* root, int max_val, int& ans){
        if (!root) return;
        if (root -> val >= max_val) {
            ans++;
            
        }
        max_val = max(max_val, root -> val);
        helper(root -> left, max_val, ans);
        helper(root -> right, max_val, ans);
    }
    int goodNodes(TreeNode* root) {
        int max_val = root -> val;
        int ans = 0;
        helper(root, max_val, ans);

        return ans;
    }
};