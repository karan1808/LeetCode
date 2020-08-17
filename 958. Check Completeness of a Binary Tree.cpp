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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;
        bool fn = false;
        q.push(root);
        while (q.size()) {
            TreeNode* front = q.front(); q.pop();
            if (!front) {fn = true;}
            if (fn && front) {return false;}
            if (front) {
                if (front->left) {q.push(front->left);} else {q.push(NULL);}
                if (front->right) {q.push(front->right);} else {q.push(NULL);}
            }
        }
        return true;
    }
};