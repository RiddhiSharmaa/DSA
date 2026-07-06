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
    int ans = 0;
    void helper(int temp, TreeNode* root){
        if (!root) return;
        if (!root -> left && !root -> right){
            temp = ((temp*10) + root -> val);
            ans += temp;
            return;
        }
        temp = ((temp*10) + root -> val);
        helper(temp, root -> left);
        helper(temp, root -> right);
        temp = (temp - root -> val) / 10;
    }
    int sumNumbers(TreeNode* root) {
        int temp = 0;
        helper(temp, root);
        return ans;
    }
};