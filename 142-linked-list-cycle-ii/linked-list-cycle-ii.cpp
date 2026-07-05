/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        
        vector<ListNode*> visited;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            for (size_t i = 0; i < visited.size(); i++) {
                if (visited[i] == curr) {
                    return curr;
                }
            }
            visited.push_back(curr);
            curr = curr->next;
        }
        
        return nullptr;
    }
};