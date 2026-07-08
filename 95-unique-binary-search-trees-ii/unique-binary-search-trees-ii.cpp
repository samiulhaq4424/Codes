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
    vector<TreeNode*> gen(int s, int e) {
        vector<TreeNode*> res;
        if (s > e) {
            res.push_back(nullptr);
            return res;
        }

        for (int i = s; i <= e; i++) {
            vector<TreeNode*> L = gen(s, i - 1);
            vector<TreeNode*> R = gen(i + 1, e);

            for (TreeNode* l : L) {
                for (TreeNode* r : R) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }
        return res;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return gen(1, n);
    }
};