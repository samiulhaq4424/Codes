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
    vector<TreeNode*> build(int start, int end) {
        vector<TreeNode*> result;
        if (start > end) {
            result.push_back(nullptr);
            return result;
        }
        if (start == end) {
            result.push_back(new TreeNode(start));
            return result;
        }
        result.reserve(100); // Approximate for small n
        for (int rootVal = start; rootVal <= end; ++rootVal) {
            vector<TreeNode*> left = build(start, rootVal - 1);
            vector<TreeNode*> right = build(rootVal + 1, end);
            for (TreeNode* l : left) {
                for (TreeNode* r : right) {
                    TreeNode* root = new TreeNode(rootVal);
                    root->left = l;
                    root->right = r;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return build(1, n);
    }
};