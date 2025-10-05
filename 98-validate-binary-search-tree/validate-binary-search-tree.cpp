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
    bool helper(TreeNode* root, long lb, long ub){
        if(!root){
            return true;
        }
        if(root->val <= lb || root->val >= ub){
            return false;
        }

        return helper(root->left,lb,root->val) && helper(root->right,root->val,ub);
    }
    bool isValidBST(TreeNode* root) {
        if(!root || !root->left && !root->right){
            return true;
        }
        long lb = LONG_MIN;
        long ub = LONG_MAX;
        bool ans = helper(root,lb,ub);
        return ans;
    }
};