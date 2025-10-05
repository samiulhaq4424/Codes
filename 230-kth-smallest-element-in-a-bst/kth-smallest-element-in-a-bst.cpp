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
    void helper(TreeNode* root, int &dist, int k, int &ans){
        if(!root){
            return;
        }
        helper(root->left,dist,k,ans);
        ++dist;
        if(dist == k){
            ans = root->val;
            return;
        }
        helper(root->right,dist,k,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        int dist = 0;
        helper(root,dist,k,ans);
        return ans;
    }
};