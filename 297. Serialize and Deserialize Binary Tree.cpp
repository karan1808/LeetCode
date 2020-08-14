/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        string ans;
        queue<TreeNode*> q;
        if (root == NULL) {return "#";}
        q.push(root);
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            if (temp) {ans += to_string(temp->val); ans += " ";} else {ans += "#"; ans += " ";}
            if (temp) {q.push(temp->left); q.push(temp->right);}
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        istringstream in(data);
        string val;
        in >> val;
        if (val == "#") {return NULL;}

        TreeNode* root = new TreeNode(stoi(val));

        queue<TreeNode*> todo;
        todo.push(root);

        while (!todo.empty()) {

            TreeNode* tem = todo.front();
            todo.pop();
            in >> val;

            if (val != "#") {
                tem->left = new TreeNode(stoi(val));
                todo.push(tem->left);
            }

            in >> val;

            if (val != "#") {
                tem->right = new TreeNode(stoi(val));
                todo.push(tem->right);
            }

        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));