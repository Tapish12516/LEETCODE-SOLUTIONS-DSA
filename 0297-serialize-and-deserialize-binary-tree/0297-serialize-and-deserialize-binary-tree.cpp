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
    void preorder(TreeNode* root, string &s) {
        if (root == NULL) {
            s += "#,";
            return;
        }
        s += to_string(root->val) + ",";
        preorder(root->left, s);
        preorder(root->right, s);
    }
    string serialize(TreeNode* root) {
        string s = "";
        preorder(root, s);
        return s;
    }
    TreeNode* solve(string &s, int &pos) {
        if (s[pos] == '#') {
            pos += 2;
            return NULL;
        }
        int sign = 1;
        if (s[pos] == '-') {
            sign = -1;
            pos++;
        }
        int x = 0;
        while (s[pos] != ',') {
            x = x * 10 + (s[pos] - '0');
            pos++;
        }
        pos++;
        TreeNode* root = new TreeNode(x * sign);
        root->left = solve(s, pos);
        root->right = solve(s, pos);
        return root;
    }
    TreeNode* deserialize(string data) {
        int pos = 0;
        return solve(data, pos);
    }
};


// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));