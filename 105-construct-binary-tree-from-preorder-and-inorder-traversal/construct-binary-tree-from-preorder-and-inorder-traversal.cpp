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
    TreeNode* helper(int& i, int left, int right, vector<int>& preorder, 
    unordered_map<int, int>& mpp){
        if (i < 0 || i >= preorder.size()) return nullptr;
        if (left > right) return nullptr;
        if (left == right) {
            int ind = i;
            i++;
            return new TreeNode(preorder[ind]);
        }
        int ind = i;
        TreeNode* newNode = new TreeNode(preorder[ind]);
        i++;
        newNode -> left = helper(i, left, mpp[preorder[ind]]-1, preorder, mpp);
        newNode -> right = helper(i, mpp[preorder[ind]]+1, right, preorder, mpp);
        return newNode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int>mpp;

        for (int i = 0; i < inorder.size(); i++){
            mpp[inorder[i]] = i;
        }
        int idx = 0;
        return helper(idx, 0, preorder.size()-1, preorder, mpp);
    }
};