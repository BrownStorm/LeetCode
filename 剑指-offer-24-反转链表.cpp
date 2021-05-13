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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *prenode = head, *node = head->next, *nextnode = node->next;
        head->next = nullptr;
        node->next = prenode;

        while (nextnode) {
            prenode = node;
            node = nextnode;
            nextnode = node->next;
            node->next = prenode;
        }

        return node;
    }
};