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
    int helper(TreeNode* root, int &cameras) {
        if(!root){
            return 1;
        }

        int leftSub = helper(root->left,cameras);
        int rightSub = helper(root->right,cameras);

        if(leftSub == 0 || rightSub == 0){
            ++cameras;
            return 2;
        }
        if(leftSub == 2 || rightSub == 2){
            return 1;
        }
        if(leftSub == 1 && rightSub ==1){
            return 0;
        }
        return 0;
    }

    int minCameraCover(TreeNode* root) {
        if(!root){
            return 0;
        }

        int cameras = 0;
        if(helper(root,cameras) == 0){
            ++cameras;
        }
        return cameras;
    }
};