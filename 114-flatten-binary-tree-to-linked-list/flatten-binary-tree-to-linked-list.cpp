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
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        vector<TreeNode*> nodes;
        preorder(root, nodes);

        for (size_t i = 0; i < nodes.size() - 1; i++) {
            nodes[i]->left = nullptr;
            nodes[i]->right = nodes[i + 1];
        }

        nodes.back()->left = nullptr;
        nodes.back()->right = nullptr;
    }

    void preorder(TreeNode* node, vector<TreeNode*>& nodes) {
        if (node == nullptr) {
            return;
        }
        nodes.push_back(node);
        preorder(node->left, nodes);
        preorder(node->right, nodes);
    }
};