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

    TreeNode* inorder(TreeNode* root, TreeNode* &ans){
        if (!root) return nullptr;
        
        int hleft = height(root -> left);
        int hright = height(root -> right);

        if (hleft == hright ) ans = root;
        else if (hleft > hright) inorder(root -> left, ans);
        else if (hleft < hright) inorder(root -> right, ans);
        
        return root;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (!root) return nullptr;
        TreeNode* ans = nullptr;
        TreeNode* temp = inorder(root, ans);
        return ans;
    }
};