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
    void mapParents(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &parents,
                    int start, TreeNode* &targetNode) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            if(cur->val == start){
                targetNode = cur;
            }
            if(cur->left){
                q.push(cur->left);
                parents[cur->left] = cur;
            }
            if(cur->right){
                q.push(cur->right);
                parents[cur->right] = cur;
            }
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        if(!root){
            return 0;
        }
        unordered_map<TreeNode*,TreeNode*> parents;
        TreeNode* targetNode = NULL;
        mapParents(root,parents,start,targetNode);

        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(targetNode);
        visited[targetNode] = true;
        int time = 0;

        while(!q.empty()) {
            int size = q.size();
            bool flag = false;
            for(int i=0;i<size;i++){
                TreeNode* cur = q.front();
                q.pop();
                if(cur->left && !visited[cur->left]){
                    flag = true;
                    q.push(cur->left);
                    visited[cur->left] = true;
                }
                if(cur->right && !visited[cur->right]){
                    flag = true;
                    q.push(cur->right);
                    visited[cur->right] = true;
                }
                if(parents[cur] && !visited[parents[cur]]){
                    flag = true;
                    q.push(parents[cur]);
                    visited[parents[cur]] = true;
                }
            }
            if(flag == true){
                ++time;
            }
        }
        return time;
    }
};