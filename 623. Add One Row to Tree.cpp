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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode* temp = new TreeNode(v);
            temp->left = root;
            return temp;
        }
        recur(root, v, d, 2);
        return root;
    }
    void recur(TreeNode* root, int v, int d, int c) {
        if (!root) {return;}
        if (c == d) {
            TreeNode* templeft = root->left;
            TreeNode* tempright = root->right;
            root->left = new TreeNode(v);
            root->left->left = templeft;
            root->right = new TreeNode(v);
            root->right->right = tempright;
        }
        recur(root->left, v, d, c + 1);
        recur(root->right, v, d, c + 1);
    }
};