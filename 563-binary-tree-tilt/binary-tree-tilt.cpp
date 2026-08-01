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
    int totalTilt = 0;

    int calculateSum(TreeNode* root) {
        if (!root) return 0;

        int leftSum = calculateSum(root->left);
        int rightSum = calculateSum(root->right);

        totalTilt += abs(leftSum - rightSum);

        return root->val + leftSum + rightSum;
    }

    public:
    int findTilt(TreeNode* root) {
        calculateSum(root);
        return totalTilt;
    }
};