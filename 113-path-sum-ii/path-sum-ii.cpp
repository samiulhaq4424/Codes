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
    vector<vector<int>> result;
    vector<int> currentPath;

    void findPaths(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return;
        }
        currentPath.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            if (targetSum == root->val) {
                result.push_back(currentPath);
            }
        } else {
            findPaths(root->left, targetSum - root->val);
            findPaths(root->right, targetSum - root->val);
        }
        currentPath.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        result.clear();
        currentPath.clear();
        findPaths(root, targetSum);
        return result;
    }
};