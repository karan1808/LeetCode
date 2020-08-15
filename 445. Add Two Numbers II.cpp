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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        if (!l1 && !l2) {return NULL;}

        ListNode* rl1 = rev(l1);
        ListNode* rl2 = rev(l2);

        int rem = 0;
        ListNode* out = new ListNode(0);
        ListNode* res = out;
        while (rl1 && rl2) {
            res->next = new ListNode((rl1->val + rl2->val + rem) % 10);
            rem = (rl1->val + rl2->val + rem) / 10;
            res = res->next;
            rl1 = rl1->next;
            rl2 = rl2->next;
        }
        while (rl1) {
            res->next = new ListNode((rl1->val + rem) % 10);
            rem = (rl1->val + rem) / 10;
            res = res->next;
            rl1 = rl1->next;
        }
        while (rl2) {
            res->next = new ListNode((rl2->val + rem) % 10);
            rem = (rl2->val + rem) / 10;
            res = res->next;
            rl2 = rl2->next;
        }
        if (rem > 0)res->next = new ListNode(rem);
        out = out->next;
        out = rev(out);
        return out;
        // return NULL;
    }
    ListNode* rev(ListNode* head) {
        ListNode *curr, *pre = NULL, *next;
        curr = head;
        while (curr) {
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        return pre;
    }
};