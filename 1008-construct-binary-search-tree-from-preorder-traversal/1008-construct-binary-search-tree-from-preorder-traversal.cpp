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
    TreeNode* build(vector<int>& preorder, int& index, long long lower, long long upper) {
        if (index >= (int)preorder.size()) {
            return nullptr;
        }
        int value = preorder[index];
        if (value <= lower || value >= upper) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(value);
        index++;
        root->left = build(preorder, index, lower, value);
        root->right = build(preorder, index, value, upper); 
        return root;
    }
    void printInorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        } 
        printInorder(root->left);
        cout << root->val << " ";
        printInorder(root->right);
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return build(preorder, index, LLONG_MIN, LLONG_MAX);
    }
    void printTree(TreeNode* root) {
        printInorder(root);
    }
};