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
    int helper(TreeNode* root, int &pathSum) {
        if(!root){
            return 0;
        }
        int lsum = max(0,helper(root->left, pathSum));
        int rsum = max(0,helper(root->right, pathSum));
        pathSum = max(pathSum, root->val+lsum+rsum);
        return root->val+max(lsum,rsum);
    }
    int maxPathSum(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int pathSum = INT_MIN;
        helper(root, pathSum);
        return pathSum;
    }
};