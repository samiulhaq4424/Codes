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
    int findBottomLeftValue(TreeNode* root) {
        int leftMost = 0;
        if(!root){
            return leftMost;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            long temp = LONG_MAX;
            for(int i=0;i<size;i++){
                TreeNode* cur = q.front();
                q.pop();
                if(temp == LONG_MAX){
                    temp = cur->val;
                }
                if(cur->left){
                    q.push(cur->left);
                }
                if(cur->right){
                    q.push(cur->right);
                }
            }
            if(temp != LONG_MAX)
                leftMost = temp;
        }
        return leftMost;
    }
};