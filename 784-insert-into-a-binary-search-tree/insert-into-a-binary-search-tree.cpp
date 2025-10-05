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
    TreeNode* insertIntoBST(TreeNode* root, int data) {
        if(!root) {
            return new TreeNode(data);
        }
        TreeNode* cur = root;
        while(cur){
            if(cur->val > data){
                if(cur->left != NULL){
                    cur = cur->left;
                } else {
                    TreeNode* node = new TreeNode(data);
                    cur->left = node;
                    break;
                }
            }
            else if(cur->val < data){
                if(cur->right != NULL){
                    cur = cur->right;
                } else {
                    TreeNode* node = new TreeNode(data);
                    cur->right = node;
                    break;
                }
            }
        }
        return root;
    }
};