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
private:
    ListNode* head;
    int size;
public:
    Solution(ListNode* head) {
        this->head = head;
        size = 0;
        ListNode* curr = head;
        while (curr) {
            size++;
            curr = curr->next;
        }
    }
    
    int getRandom() {
        int idx = rand() % size;
        ListNode* curr = head;
        for (int i = 0; i < idx; i++) {
            curr = curr->next;
        }
        return curr->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */