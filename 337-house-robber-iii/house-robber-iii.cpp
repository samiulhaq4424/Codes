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
    int rob(TreeNode* root) {
        pair<int, int> result = robHelper(root);
        return max(result.first, result.second);
    }
    
private:
    pair<int, int> robHelper(TreeNode* node) {
        if (!node) return {0, 0};
        
        pair<int, int> left = robHelper(node->left);
        pair<int, int> right = robHelper(node->right);
        
        int withNode = node->val + left.second + right.second;
        int withoutNode = max(left.first, left.second) + max(right.first, right.second);
        
        return {withNode, withoutNode};
    }
};