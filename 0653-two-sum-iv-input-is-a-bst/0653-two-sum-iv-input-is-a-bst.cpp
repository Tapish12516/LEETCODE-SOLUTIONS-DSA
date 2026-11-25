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
    bool search(TreeNode* root, int target, TreeNode* curr) {
        if (!root) return false;
        if (root->val == target && root != curr) return true;        
        if (target > root->val)
            return search(root->right, target, curr);
        return search(root->left, target, curr);
    }
    bool dfs(TreeNode* curr, TreeNode* originalRoot, int k) {
        if (!curr) return false;        
        int difference = k - curr->val;
        if (search(originalRoot, difference, curr)) 
            return true;       
        return dfs(curr->left, originalRoot, k) || dfs(curr->right, originalRoot, k);
    }
    bool findTarget(TreeNode* root, int k) {
        return dfs(root, root, k);
    }
};