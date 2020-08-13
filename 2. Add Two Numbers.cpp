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
        ListNode* res = new ListNode(0);
        ListNode* kl = res;
        int rem = 0;
        while (l1 && l2) {
            ListNode* root = new ListNode;
            root->val = (l1->val + l2->val + rem) % 10;
            rem = (l1->val + l2->val + rem) / 10;
            kl->next = root;
            kl = kl->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            ListNode* root = new ListNode;
            root->val = (l1->val + rem) % 10;
            rem = (l1->val + rem) / 10;
            kl->next = root;
            kl = kl->next;
            l1 = l1->next;
        }
        while (l2) {
            ListNode* root = new ListNode;
            root->val = (l2->val + rem) % 10;
            rem = (l2->val + rem) / 10;
            kl->next = root;
            kl = kl->next;
            l2 = l2->next;
        }
        if (rem > 0) {
            ListNode* root = new ListNode;
            root->val = rem;
            kl->next = root;
            kl = kl->next;
        }
        return res->next;
    }
};