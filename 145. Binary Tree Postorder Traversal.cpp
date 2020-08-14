/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) {return res;}
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* x = s.top();
            res.push_back(x->val);
            s.pop();
            if (x->left) {
                s.push(x->left);
            }
            if (x->right) {
                s.push(x->right);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};