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
    TreeNode* helper(vector<int> &preorder, int &indx, long lb, long ub){
        if(indx >= preorder.size()){
            return NULL;
        }
        if(preorder[indx] <= lb || preorder[indx] >= ub){
            return NULL;
        }

        TreeNode *node = new TreeNode(preorder[indx]);
        ++indx;
        node->left = helper(preorder,indx,lb,node->val);
        node->right = helper(preorder,indx,node->val,ub);
        return node;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int indx = 0;
        long lb = LONG_MIN;
        long ub = LONG_MAX;
        return helper(preorder,indx,lb,ub);
    }
};