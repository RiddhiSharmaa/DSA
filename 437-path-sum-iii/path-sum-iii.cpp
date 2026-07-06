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
    void dfs(TreeNode* curr, long long targetSum, int& ans){
        if (!curr) return;
        if (targetSum == curr -> val){
            ans++;
        }
        dfs(curr -> left, targetSum - curr -> val, ans);
        dfs(curr -> right, targetSum - curr -> val, ans);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        queue<TreeNode*>q;
        q.push(root);
        int ans = 0;

        while (!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i++){
                TreeNode* curr = q.front();
                q.pop();
                dfs(curr, targetSum, ans);

                if (curr -> left){
                    q.push(curr -> left);
                }
                if (curr -> right){
                    q.push(curr -> right);
                }
            }
        }

        return ans;
    }
};