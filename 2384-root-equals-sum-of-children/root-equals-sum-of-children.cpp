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
    bool checkTree(TreeNode* root) {
        if(!root){
            return true;
        }
        if(checkTree(root->left)==false){
            return false;
        }
        if(checkTree(root->right) == false){
            return false;
        }

        int sum = 0;
        bool flag = false;
        if(root->left){
            sum += root->left->val;
            flag = true;
        }
        if(root->right){
            sum += root->right->val;
            flag = true;
        }
        if(flag && root->val != sum){
            return false;
        }
        return true;
    }
};