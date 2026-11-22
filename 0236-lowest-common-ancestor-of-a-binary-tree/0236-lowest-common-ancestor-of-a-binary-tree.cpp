/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q) {
            return root;
        }
        auto r = lowestCommonAncestor(root->right, p, q);
        auto l = lowestCommonAncestor(root->left, p, q);
        if (l == NULL) return r;
        if (r == NULL) return l;
        else return root;
    }
};


    // TreeNode* dfs(TreeNode* root , TreeNode* p, TreeNode* q){
    //     if(!root) return nullptr;
    //     if(root == p || root == q) return root;
    //     TreeNode* leftnode = dfs(root->left , p, q);
    //     TreeNode* rightnode = dfs(root->right , p, q);
    //     if(leftnode != nullptr && rightnode != nullptr) return root;
    //     if(!leftnode) return rightnode;
    //     return leftnode;
    // }
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     return dfs(root , p , q);
    // }