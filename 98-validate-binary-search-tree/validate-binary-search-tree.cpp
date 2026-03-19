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
    bool helper(TreeNode* root, ll mini, ll maxi){
        if (!root) return true;

        if (root -> val <= mini || root -> val >= maxi) return false;

        bool ans1 = helper(root -> left, mini, root -> val);
        bool ans2 = helper(root -> right, root -> val, maxi);

        return ans1 && ans2;

    }
    bool isValidBST(TreeNode* root) {
        return helper(root, LLONG_MIN, LLONG_MAX);
    }
};