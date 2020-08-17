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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        if (!root) {return res;}
        st.push(root);
        while (!st.empty()) {
            root = st.top();
            res.push_back(root->val);
            st.pop();
            if (root->right) {
                st.push(root->right);
            }
            if (root->left) {
                st.push(root->left);
            }
        }
        return res;
    }
};