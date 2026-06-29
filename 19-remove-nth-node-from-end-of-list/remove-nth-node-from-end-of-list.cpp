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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* a = &dummy;
        ListNode* b = &dummy;
        
        for (int i = 0; i <= n; ++i) {
            a = a->next;
        }
        
        while (a != nullptr) {
            a = a->next;
            b = b->next;
        }
        
        ListNode* t = b->next;
        b->next = b->next->next;
        delete t;
        
        return dummy.next;
    }
};