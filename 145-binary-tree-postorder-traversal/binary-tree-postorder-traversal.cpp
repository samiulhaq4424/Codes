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
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root){
            return ans;
        }

        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);
        while(!s1.empty()) {
            TreeNode* cur = s1.top();
            s1.pop();
            s2.push(cur);
            if(cur->left != NULL){
                s1.push(cur->left);
            }
            if(cur->right != NULL){
                s1.push(cur->right);
            }
        }

        while(!s2.empty()){
            TreeNode* cur = s2.top();
            s2.pop();
            ans.push_back(cur->val);
        }
        return ans;
    }
};