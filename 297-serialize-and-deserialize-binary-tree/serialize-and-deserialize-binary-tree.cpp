/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void helper(TreeNode* root, string& serial){
        if (!root) return;
        queue<TreeNode*>q;
        q.push(root);

        while (!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                if (!node) {
                    serial += "N,";
                    continue;
                }
                serial += (to_string(node -> val) + ",");
                q.push(node -> left);
                q.push(node -> right);
            }
        }
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        string serial = "";
        helper(root, serial);
        return serial;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return nullptr;
        vector<string>nodes;
        string num = "";

        for (int i = 0; i < data.size(); i++){
            if (data[i] != ','){
                num += data[i];
            } else {
                nodes.push_back(num);
                num = "";
            }
        }
        nodes.push_back(num);

        TreeNode* root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*>q;
        q.push(root);
        int i = 1;

        while (!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if (nodes[i] != "N"){
                node -> left = new TreeNode(stoi(nodes[i]));
                q.push(node -> left);
            } 
            i++;

            if (nodes[i] != "N"){
                node -> right = new TreeNode(stoi(nodes[i]));
                q.push(node -> right);
            } 
            i++;
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));