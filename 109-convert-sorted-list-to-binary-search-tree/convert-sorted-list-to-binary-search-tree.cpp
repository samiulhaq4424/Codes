/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* helper(ListNode *&head, int n){
        if(n==0){
            return NULL;
        }

        TreeNode *node = new TreeNode();
        node->left = helper(head,n/2);
        node->val = head->val;
        head = head->next;
        node->right = helper(head,(n-1)/2);
        return node;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        int n = 0;
        ListNode *cur = head;
        while(cur){
            ++n;
            cur = cur->next;
        }
        return helper(head,n);
    }
};