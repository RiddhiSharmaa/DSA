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
    using ll = long long;
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, ll>>q;
        q.push({root, 0});
        ll ans = 0;

        while (!q.empty()){
            int size = q.size();
            int minIdx = q.front().second;
            ll first = -1, last = -1;

            for (int i = 0; i < size; i++){
                TreeNode* node = q.front().first;
                ll idx = q.front().second - minIdx;
                q.pop();
                if (i == 0) first = idx;
                if (i == size-1) last = idx;
                if (node -> left) q.push({node -> left, 2*idx+1});
                if (node -> right) q.push({node -> right, 2*idx+2});
            }

            if (first != -1 && last != -1) ans = max(ans, last-first+1);
        }

        return (int)ans;
    }
};