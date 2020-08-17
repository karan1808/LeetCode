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
    TreeNode* pruneTree(TreeNode* root) {
        if (sum(root) > 0) {
            return root;
        } else {
            return NULL;
        }
    }
    int sum(TreeNode* root) {
        if (!root) {return 0;}
        int res = root->val;
        if (sum(root->left) > 0) {res += sum(root->left);} else {
            root->left = NULL;
        }
        if (sum(root->right) > 0) {res += sum(root->right);} else {
            root->right = NULL;
        }
        return res;
    }
};