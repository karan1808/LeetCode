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
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        inorder(root, L, R, sum);
        return sum;
    }
    void inorder(TreeNode* root, int L, int R, int& sum) {
        if (root) {
            inorder(root->left, L, R, sum);
            if (root->val >= L && root->val <= R) {
                sum += root->val;
            }
            inorder(root->right, L, R, sum);
        }
        return;
    }
};