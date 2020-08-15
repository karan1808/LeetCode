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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b;
        inorder(root1, a);
        inorder(root2, b);
        int i = 0;
        while (i < b.size()) {
            a.push_back(b[i]);
            i++;
        }
        sort(a.begin(), a.end());
        return a;
    }
    void inorder(TreeNode* root, vector<int>& v) {
        if (!root) {return;}
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
};