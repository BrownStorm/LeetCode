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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 && !l2) return l1;
        else if (!l1 && l2) return l2;
        else if (!l1 && !l2) return l1;

        ListNode *ans;
        if (l1->val < l2->val) {
            ans = l1;
            l1 = l1->next;
        }else {
            ans = l2;
            l2 = l2->next;
        }
        ListNode *prenode = ans, *node;
        while (l1 || l2) {
            if (!l1) {
                prenode->next = l2;
                break;
            }
            if (!l2) {
                prenode->next = l1;
                break;
            }
            if (l1->val < l2->val) {
                node = l1;
                l1 = l1->next;
            }else {
                node = l2;
                l2 = l2->next;
            }
            prenode->next = node;
            prenode = node;
        }
        return ans;
    }
};