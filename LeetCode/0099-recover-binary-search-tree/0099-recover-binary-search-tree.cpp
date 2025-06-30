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
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;
        
        function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if (!node) return;
            
            inorder(node->left);
            
            if (prev && prev->val > node->val) {
                if (!first) {
                    first = prev;
                    second = node;
                } else {
                    second = node;
                }
            }
            prev = node;
            
            inorder(node->right);
        };
        
        inorder(root);
        
        if (first && second) {
            swap(first->val, second->val);
        }
    }
};