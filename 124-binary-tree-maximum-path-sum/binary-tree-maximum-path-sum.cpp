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
int maxPathSumHelper(TreeNode* node, int& maxSum) {
        if (!node) return 0;

        int leftMax = max(0, maxPathSumHelper(node->left, maxSum));
        int rightMax = max(0, maxPathSumHelper(node->right, maxSum));

        maxSum = max(maxSum, node->val + leftMax + rightMax);

        return node->val + max(leftMax, rightMax);
    }

public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxPathSumHelper(root, maxSum);
        return maxSum;
    }
};