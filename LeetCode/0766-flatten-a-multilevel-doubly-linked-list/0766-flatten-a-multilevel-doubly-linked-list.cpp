/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr = head;
        while (curr) {
            if (curr->child) {
                Node* next = curr->next;
                Node* child = flatten(curr->child);
                curr->child = nullptr;
                curr->next = child;
                child->prev = curr;
                while (child->next) {
                    child = child->next;
                }
                child->next = next;
                if (next) {
                    next->prev = child;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};