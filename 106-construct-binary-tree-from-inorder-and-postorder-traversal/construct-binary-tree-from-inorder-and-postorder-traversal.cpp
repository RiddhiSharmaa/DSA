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
    TreeNode* helper(int& i, int left, int right, vector<int>& postorder, 
    unordered_map<int, int>& mpp){
        if (left > right || i >= postorder.size()) return nullptr;
        int node = postorder[i];
        TreeNode* newNode = new TreeNode(node);
        i++;
        newNode -> right = helper(i, mpp[node]+1, right, postorder, mpp);
        newNode -> left = helper(i, left, mpp[node]-1, postorder, mpp);
        return newNode;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int>mpp;

        for (int i = 0; i < inorder.size(); i++){
            mpp[inorder[i]] = i;
        }
        int idx = 0;
        reverse(postorder.begin(), postorder.end());
        return helper(idx, 0, postorder.size()-1, postorder, mpp);
    }
};