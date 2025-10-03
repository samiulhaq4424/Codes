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
    int heightTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        int lh = heightTree(root->left);
        int rh = heightTree(root->right);
        return 1+max(lh,rh);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root){
            return {};
        }
        int height = heightTree(root);
        vector<vector<int>> ans(height);
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector<int> temp;
            for(int i=0; i<size; i++) {
                TreeNode* cur = q.front();
                q.pop();
                temp.push_back(cur->val);
                if(cur->left != NULL) {
                    q.push(cur->left);
                }
                if(cur->right != NULL) {
                    q.push(cur->right);
                }
            }
            ans[--height]=temp;
        }
        return ans;
    }
};