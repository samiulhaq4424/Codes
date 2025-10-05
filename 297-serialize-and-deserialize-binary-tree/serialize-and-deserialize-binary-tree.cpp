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
        if (!root) {
            return "";
        }
        string str = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if (cur == NULL) {
                str.append("#,");
            } else {
                str.append(to_string(cur->val) + ',');
            }
            if (cur != NULL) {
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") {
            return NULL;
        }
        string str = "";
        stringstream s(data);
        queue<TreeNode*> q;

        getline(s, str, ',');
        TreeNode* node = new TreeNode(stoi(str));
        q.push(node);

        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();

            getline(s, str, ',');
            if (str == "#") {
                cur->left = NULL;
            } else {
                TreeNode* node = new TreeNode(stoi(str));
                cur->left = node;
                q.push(node);
            }

            getline(s, str, ',');
            if (str == "#") {
                cur->right = NULL;
            } else {
                TreeNode* node = new TreeNode(stoi(str));
                cur->right = node;
                q.push(node);
            }
        }
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));