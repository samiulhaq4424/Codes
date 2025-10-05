/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parentsMap(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &parents) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
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

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(!root){
            return ans;
        }
        unordered_map<TreeNode*,TreeNode*> parents;
        parentsMap(root,parents);

        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int dist = 0;

        while(!q.empty()){
            int size = q.size();
            if(dist == k){
                break;
            }
            ++dist;
            for(int i=0;i<size;i++){
                TreeNode* cur = q.front();
                q.pop();
                if(cur->left && !visited[cur->left]){
                    q.push(cur->left);
                    visited[cur->left] = true;
                }
                if(cur->right && !visited[cur->right]){
                    q.push(cur->right);
                    visited[cur->right] = true;
                }
                if(parents[cur] && !visited[parents[cur]]){
                    q.push(parents[cur]);
                    visited[parents[cur]] = true;
                }
            }
        }

        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            ans.push_back(cur->val);
        }
        return ans;
    }
};