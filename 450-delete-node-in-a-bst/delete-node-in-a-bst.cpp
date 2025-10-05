/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* Predecessor(TreeNode* root) {
        TreeNode* cur = root->left;
        while (cur->right) {
            cur = cur->right;
        }
        return cur;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return NULL;
        }

        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else if (root->val == key) {
            if (!root->left && !root->right) {
                return NULL;
            } else if (root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            } else if (root->left != NULL && root->right != NULL) {
                TreeNode* pred = Predecessor(root);
                root->val = pred->val;
                root->left = deleteNode(root->left, pred->val);
            }
        }
        return root;
    }
};