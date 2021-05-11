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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        int count = 1;
        ListNode* node = head;
        ListNode* ans = head;
        while (node) {
            if (count > k) ans = ans->next;
            else if (++count == k) ans = head;
            node = node->next;
        }
        return ans;
    }
};