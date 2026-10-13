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
    int maxDepth(TreeNode* root) {
    if(root == nullptr) return 0;
    if(!root->left && !root->right) return 1;
    int mindepth = 0;
    if(!root->left)  return 1 + maxDepth(root->right);
    else if(!root->right) return 1 + maxDepth(root->left);
    int leftd = maxDepth(root->left);
    int rightd = maxDepth(root->right);
    mindepth = (leftd > rightd) ? leftd : rightd;
    return 1 + mindepth;
    }
};