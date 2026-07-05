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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        map<int, vector<int>>mpp;
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});

        while (!q.empty()){
            int size = q.size();
            map<int, vector<int>>temp;

            for (int i = 0; i < size; i++){
                TreeNode* node = q.front().first;
                int lvl = q.front().second;
                q.pop();
                temp[lvl].push_back(node -> val);

                if (node -> left){
                    q.push({node -> left, lvl-1});
                }
                if (node -> right){
                    q.push({node -> right, lvl+1});
                }

            }
            
            for (auto& [c, v] : temp){
                sort(v.begin(), v.end());
                for (int k : v){
                    mpp[c].push_back(k);
                }
            }
        }

        for (auto& [c, v] : mpp){
            ans.push_back(v);
        }

        return ans;
    }
};