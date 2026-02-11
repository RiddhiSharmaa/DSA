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
        int left = height(root -> left);
        int right = height(root -> right);
        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        if (!root) return true;

        int l = height(root -> left);
        int r = height(root -> right);

        if (abs(l-r) > 1) return false;
        bool a1 = isBalanced(root -> left);
        bool a2 = isBalanced(root -> right);

        if (!a1 || !a2) return false;

        return true;
    }
};