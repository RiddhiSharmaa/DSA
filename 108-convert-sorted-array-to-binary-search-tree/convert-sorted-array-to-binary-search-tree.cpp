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
    TreeNode* helper(int low, int high, vector<int>& nums){
        if (low > high || low < 0 || high >= nums.size()) return nullptr;
        if (low == high) return new TreeNode(nums[low]);
        int mid = (low + high)/2;
        TreeNode* newNode = new TreeNode(nums[mid]);

        newNode -> left = helper(low, mid-1, nums);
        newNode -> right = helper(mid+1, high, nums);
        return newNode;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(0, nums.size()-1, nums);
    }
};