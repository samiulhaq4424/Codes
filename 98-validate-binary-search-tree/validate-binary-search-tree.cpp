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
    void traverse(TreeNode* root, vector<int>& elements) {
        if (root == nullptr) {
            return;
        }
        traverse(root->left, elements);
        elements.push_back(root->val);
        traverse(root->right, elements);
    }

    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        vector<int> sortedVals;
        traverse(root, sortedVals);
        for (size_t i = 0; i < sortedVals.size() - 1; i++) {
            if (sortedVals[i] >= sortedVals[i + 1]) {
                return false;
            }
        }
        return true;
    }
};