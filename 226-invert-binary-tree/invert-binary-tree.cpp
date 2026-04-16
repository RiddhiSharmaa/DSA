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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;

        queue<TreeNode*>q;
        q.push(root);

        while (!q.empty()){
            int size = q.size();

            for (int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                TreeNode* temp1 = (node -> left) ? node -> left : nullptr;
                TreeNode* temp2 = (node -> right) ? node -> right : nullptr;
                node -> left = temp2;
                node -> right = temp1;
                if (node -> left) q.push(node -> left);
                if (node -> right) q.push(node -> right);
            }
        }

        return root;
    }
};