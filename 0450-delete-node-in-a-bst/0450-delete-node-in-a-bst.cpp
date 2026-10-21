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
    TreeNode* helper(TreeNode* root){
        if(root->left == nullptr) return root->right;
        if(root->right == nullptr) return root->left;
        TreeNode* rightchild = root->right;
        TreeNode* leftchild = root->left;
        TreeNode* leftmostofright = rightchild;
        while(leftmostofright->left != nullptr){
            leftmostofright = leftmostofright->left;
        }
        leftmostofright->left = leftchild;
        return rightchild;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return root;
        if(root->val == key) return helper(root);
        if(root->val > key) root->left = deleteNode(root->left , key);
        else root->right = deleteNode(root->right , key);
        return root;
    }
};