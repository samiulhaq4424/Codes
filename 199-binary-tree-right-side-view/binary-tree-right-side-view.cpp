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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;

        vector<TreeNode*> q;
        q.push_back(root);

        while (!q.empty()) {
            int sz = q.size();
            ans.push_back(q.back()->val);

            vector<TreeNode*> nextQ;
            for (int i = 0; i < sz; i++) {
                TreeNode* curr = q[i];
                if (curr->left) nextQ.push_back(curr->left);
                if (curr->right) nextQ.push_back(curr->right);
            }
            q = nextQ;
        }

        return ans;
    }
};