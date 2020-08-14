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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next || k == 1) return head;
        int n = 0;
        ListNode* curr = head;
        while (curr) {
            n++;
            curr = curr->next;
        }

        ListNode *pre = NULL, *next, *newhead;
        ListNode *t1 = NULL, *t2 = head;
        curr = head;

        while (n >= k) {

            for (int i = 0; i < k; i++) {
                next = curr->next;
                curr->next = pre;
                pre = curr;
                curr = next;
            }
            if (!newhead) {newhead = pre;}
            if (t1) {t1->next = pre;}
            t2->next = curr;
            t1 = t2;
            t2 = curr;
            pre = NULL;
            n -= k;
        }
        return newhead;
    }
};