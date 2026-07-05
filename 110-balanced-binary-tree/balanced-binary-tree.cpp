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
    int height(TreeNode* root){
        if (!root) return 0;
        int left = 1 + height(root -> left);
        int right = 1 + height(root -> right);
        return max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (!isBalanced(root -> left)) return false;
        if (!isBalanced(root -> right)) return false;
        int ht = height(root -> left) - height(root -> right);
        if (abs(ht) > 1) return false;
        return true;
    }
};