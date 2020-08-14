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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = new ListNode(0);
        ListNode* out = res;
        if (lists.size() == 0) {return NULL;}
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> p;
        if (lists.size() > 0) {
            for (auto l : lists) {
                if (l)p.push(make_pair(l->val, l));
            }
        }
        while (p.size() > 0) {
            pair<int, ListNode*> kl = p.top();
            res->next = kl.second;
            p.pop();
            ListNode* test = kl.second->next;
            res->next->next = NULL;
            if (test) {
                p.push(make_pair(test->val, test));
            }
            res = res->next;
        }
        return out->next;
    }
};