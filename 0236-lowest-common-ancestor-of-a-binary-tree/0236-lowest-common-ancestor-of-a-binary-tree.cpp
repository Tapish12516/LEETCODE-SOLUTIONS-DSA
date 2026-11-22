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
    TreeNode* dfs(TreeNode* root , TreeNode* p, TreeNode* q){
        if(!root) return nullptr;
        if(root == p || root == q) return root;
        TreeNode* leftnode = dfs(root->left , p, q);
        TreeNode* rightnode = dfs(root->right , p, q);
        if(leftnode != nullptr && rightnode != nullptr) return root;
        if(!leftnode) return rightnode;
        return leftnode;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root , p , q);
    }
};

//                  OR
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(root == NULL) return NULL;
//         if(root == p || root == q) return root;
//         TreeNode* left = lowestCommonAncestor(root->left, p, q);
//         TreeNode* right = lowestCommonAncestor(root->right, p, q);
//         if(left != NULL && right != NULL) {
//             return root;
//         }
//         if(left != NULL) return left;
//         return right;
//     }
// };