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
    TreeNode* helper(vector<int>& preorder, int preStart, int preEnd,
                     vector<int>& inorder, int inStart, int inEnd,
                     unordered_map<int, int>& inMap) {
        if(preStart>preEnd || inStart>inEnd){
            return NULL;
        }
        TreeNode *node = new TreeNode(preorder[preStart]);
        int inRoot = inMap[node->val];
        int numsLeft = inRoot - inStart;
        node->left = helper(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inRoot-1,inMap);
        node->right = helper(preorder,preStart+numsLeft+1,preEnd,inorder,inRoot+1,inEnd,inMap);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        return helper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1,
                      inMap);
    }
};