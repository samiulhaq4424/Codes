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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        long maxWidth = INT_MIN;
        queue<pair<TreeNode*,long>> q;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            long minIndex = q.front().second;
            long first=0, last=0;
            for(int i=0;i<size;i++){
                auto it = q.front();
                q.pop();
                TreeNode* cur = it.first;
                long indx = it.second - minIndex;
                if(i == 0){
                    first = indx;
                }
                if(i == size-1){
                    last = indx;
                }
                if(cur->left != NULL){
                    q.push({cur->left, 2*indx+1});
                }
                if(cur->right != NULL){
                    q.push({cur->right, 2*indx+2});
                }
            }
            maxWidth = max(maxWidth, last-first+1);
        }
        return maxWidth;
    }
};