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
    int findMaxDepth(TreeNode* root){
        if (!root) return 0;

        return 1 + max(findMaxDepth(root -> left), findMaxDepth(root -> right));
    }

    TreeNode* getLCA(TreeNode* root, int height, int &maxDepth){
        if (!root) return nullptr;
        if (height + 1 == maxDepth) return root;

        TreeNode* left = getLCA(root -> left, height+1, maxDepth);
        TreeNode* right = getLCA(root -> right, height+1, maxDepth);

        if (left && right) return root;
        return left ? left : right;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int maxDepth = findMaxDepth(root);
        TreeNode* LCA = getLCA(root, 0, maxDepth);
        return LCA;
    }
};