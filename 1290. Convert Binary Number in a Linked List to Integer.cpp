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
    int getDecimalValue(ListNode* head) {
        string s = "";
        traverse(s, head);
        reverse(s.begin(), s.end());
        int i = 0;
        int res = 0;
        for (auto c : s) {
            if (c == '1') {
                res += (1 << i);
            }
            i++;
        }
        return res;
    }
    void traverse(string& s, ListNode* head) {
        if (head) {
            if (head->val == 0) {s += '0';} else {s += '1';}
            traverse(s, head->next);
        }
        return;
    }
};