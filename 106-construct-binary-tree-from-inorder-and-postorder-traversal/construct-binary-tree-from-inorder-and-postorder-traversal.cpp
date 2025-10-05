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
    TreeNode* helper(vector<int>& inorder, int inStart, int inEnd,
                     vector<int>& postorder, int postStart, int postEnd,
                     unordered_map<int, int>& inMap) {
        if (inStart > inEnd || postStart > postEnd) {
            return NULL;
        }
        TreeNode* node = new TreeNode(postorder[postEnd]);
        int inRoot = inMap[node->val];
        int numsLeft = inRoot - inStart;
        node->left = helper(inorder,inStart,inRoot-1,postorder,postStart,postStart+numsLeft-1,inMap);
        node->right = helper(inorder,inRoot+1,inEnd,postorder,postStart+numsLeft,postEnd-1,inMap);
        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        return helper(inorder, 0, inorder.size() - 1, postorder, 0,
                      postorder.size() - 1, inMap);
    }
};