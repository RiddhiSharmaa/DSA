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
    int idx = 0;
    unordered_map<int, int>mpp;
    TreeNode* helper(vector<int>& preorder, int start, int end){
        if (end < start) return nullptr;
        if (idx >= preorder.size()) return nullptr;

        int r = preorder[idx];
        idx++;
        TreeNode* root = new TreeNode(r);
        int mid = mpp[r];

        root -> left = helper(preorder, start, mid-1);
        root -> right = helper(preorder, mid+1, end);

        return root;        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++){
            mpp[inorder[i]] = i;
        }

        return helper(preorder, 0, n);
    }
};