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
    void helper(TreeNode* root, vector<ll>& inorder){
        if (!root) return;
        helper(root -> left, inorder);
        inorder.push_back(root -> val);
        helper(root -> right, inorder);
    }
    bool isValidBST(TreeNode* root) {
        // if (!root) return true;
        // // if (isValidBST(root -> left)) if (root -> left -> val < root -> val) ;
        // // else if (root -> left -> val < root -> val) return false;
        // // if (root -> right -> val > root -> val) isValidBST(root -> right);
        // // else if (root -> right -> val < root -> val) return false;
        // bool ans1 = false, ans2 = false;
        // if (root -> left) {
        //     if (root -> left -> val < root -> val){
        //         ans1 = isValidBST(root -> left);
        //     } 
        // } else {
        //     ans1 = true;
        // }
        // if (root -> right) {
        //     if (root -> right -> val > root -> val){
        //         ans2 = isValidBST(root -> right);
        //     }
        // } else {
        //     ans2 = true;
        // }

        // return ans1 && ans2;

        vector<ll>inorder;
        helper(root, inorder);

        vector<ll>sorted = inorder;
        sort(sorted.begin(), sorted.end());

        for (int i = 0; i < sorted.size()-1; i++){
            if (sorted[i] == sorted[i+1]) return false;
        }

        return sorted == inorder;
    }
};