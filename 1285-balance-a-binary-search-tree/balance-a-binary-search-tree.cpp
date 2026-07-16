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
    TreeNode* constructBST(int low, int high, vector<int>& inorder){
        if (low == high) return new TreeNode(inorder[low]);
        if (low > high) return nullptr;

        int mid = (low + high)/2;
        TreeNode* root = new TreeNode(inorder[mid]);

        root -> left = constructBST(low, mid-1, inorder);
        root -> right = constructBST(mid+1, high, inorder);
       
        return root;
    }
    void getInorder(TreeNode* root, vector<int>& inorder){
        if (!root) return;
        getInorder(root -> left, inorder);
        inorder.push_back(root -> val);
        getInorder(root -> right, inorder);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inorder;
        getInorder(root, inorder);
        return constructBST(0, inorder.size()-1, inorder);
    }
};