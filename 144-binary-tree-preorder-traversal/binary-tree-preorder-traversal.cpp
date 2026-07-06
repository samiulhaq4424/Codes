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
    vector<int> result;

    void traverse(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        result.push_back(root->val);
        traverse(root->left);
        traverse(root->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        result.clear();
        traverse(root);
        return result;
    }
};