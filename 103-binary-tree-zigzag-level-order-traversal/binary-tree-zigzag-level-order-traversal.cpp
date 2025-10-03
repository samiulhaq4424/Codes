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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool isRev = false;
        while(!q.empty()) {
            int size = q.size();
            vector<int> temp(size);
            for(int i=0; i<size; i++){
                TreeNode* cur = q.front();
                q.pop();
                int ind = isRev ? size-1-i : i;
                temp[ind] = cur->val;
                if(cur->left != NULL){
                    q.push(cur->left);
                }
                if(cur->right != NULL){
                    q.push(cur->right);
                }
            }
            isRev = !isRev;
            ans.push_back(temp);
        }
        return ans;
    }
};