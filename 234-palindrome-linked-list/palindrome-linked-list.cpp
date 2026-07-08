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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        ListNode* s = head;
        ListNode* f = head;
        while (f && f->next) {
            s = s->next;
            f = f->next->next;
        }

        ListNode* p = nullptr;
        ListNode* c = s;
        while (c) {
            ListNode* n = c->next;
            c->next = p;
            p = c;
            c = n;
        }

        ListNode* l = head;
        ListNode* r = p;
        while (r) {
            if (l->val != r->val) return false;
            l = l->next;
            r = r->next;
        }

        return true;
    }
};