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
    void build(TreeNode* root, vector<TreeNode*>& pre){
        if (!root) return;
        pre.push_back(root);
        build(root -> left, pre);
        build(root -> right, pre);
    }
    void buildTree(vector<TreeNode*>& pre){
        for (int i = 0; i < pre.size()-1; i++){
            TreeNode* node = pre[i];
            node -> right = pre[i+1];
            node -> left = nullptr;
        }
        pre[pre.size()-1] -> left = nullptr;
        pre[pre.size()-1] -> right = nullptr;
    }
    void flatten(TreeNode* root) {
        if (!root) return;
        vector<TreeNode*>pre;
        build(root, pre);
        buildTree(pre);
        return;
    }
};