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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* cur = it.first;
            int vertical = it.second.first;
            int level = it.second.second;
            mp[vertical][level].insert(cur->val);
            if(cur->left != NULL){
                q.push({cur->left,{vertical-1,level+1}});
            }
            if(cur->right != NULL){
                q.push({cur->right,{vertical+1,level+1}});
            }
        }

        for(auto p : mp){
            vector<int> temp;
            for(auto q: p.second){
                for(auto r : q.second){
                    temp.push_back(r);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};