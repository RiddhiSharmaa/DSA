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
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        string str = "";
        queue<TreeNode*>q;
        q.push(root);

        while (!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if (node){
                str.append(to_string(node -> val));
                str.append(",");
                q.push(node -> left);
                q.push(node -> right);
            } else {
                str.append("N,");
            }   
        }

        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") return nullptr;
        vector<string>nodes;
        string temp = "";

        for (char c : data){
            if (c == ','){
                nodes.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }

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