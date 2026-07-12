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
private:
    void serializeHelper(TreeNode* root, string& s) {
        if (!root) {
            s += "#,";
            return;
        }
        s += to_string(root->val) + ",";
        serializeHelper(root->left, s);
        serializeHelper(root->right, s);
    }

    TreeNode* deserializeHelper(stringstream& ss) {
        string str;
        if (!getline(ss, str, ',')) return nullptr;
        if (str == "#") return nullptr;

        TreeNode* node = new TreeNode(stoi(str));
        node->left = deserializeHelper(ss);
        node->right = deserializeHelper(ss);
        return node;
    }

public:
    string serialize(TreeNode* root) {
        string s = "";
        serializeHelper(root, s);
        return s;
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializeHelper(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));