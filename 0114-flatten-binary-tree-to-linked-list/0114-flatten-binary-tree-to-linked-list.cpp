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
    vector<TreeNode*> v;
    void preorder(TreeNode* root) {
        if(root == NULL) return;
        v.push_back(root);
        preorder(root->left);
        preorder(root->right);
    }
    void flatten(TreeNode* root) {
        v.clear();
        preorder(root);
        for(int i = 0; i < (int)v.size(); i++) {
            v[i]->left = NULL;
            if(i + 1 < (int)v.size())
                v[i]->right = v[i + 1];
            else
                v[i]->right = NULL;
        }
    }
};