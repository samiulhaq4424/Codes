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
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        unordered_map<long long, int> prefixSum;
        prefixSum[0] = 1;
        return dfs(root, 0, targetSum, prefixSum);
    }
    
private:
    int dfs(TreeNode* node, long long currSum, int targetSum, unordered_map<long long, int>& prefixSum) {
        if (!node) return 0;
        
        currSum += node->val;
        int count = prefixSum[currSum - targetSum];
        
        prefixSum[currSum]++;
        
        count += dfs(node->left, currSum, targetSum, prefixSum);
        count += dfs(node->right, currSum, targetSum, prefixSum);
        
        prefixSum[currSum]--;
        
        return count;
    }
};