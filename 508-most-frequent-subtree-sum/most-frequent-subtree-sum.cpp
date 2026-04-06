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
    unordered_map<int, int> freq;
    int maxFreq = 0;

    int dfs(TreeNode* root) {
        if (!root) return 0;
        int sum = root->val + dfs(root->left) + dfs(root->right);
        freq[sum]++;
        maxFreq = max(maxFreq, freq[sum]);
        return sum;
    }

public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int> res;
        for (const auto& [sum, count] : freq) {
            if (count == maxFreq) {
                res.push_back(sum);
            }
        }
        return res;
    }
};