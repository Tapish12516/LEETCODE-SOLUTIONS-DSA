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
    int findmaxDpath(TreeNode* node){
        if(node == nullptr) return 0;
        int leftgain = max(0 , findmaxDpath(node->left));
        int rightgain = max(0 , findmaxDpath(node->right));
        return node->val + max(leftgain,rightgain);
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return INT_MIN;
        int leftc = max(0,findmaxDpath(root->left));
        int rightc = max(0,findmaxDpath(root->right));
        int current = root->val + leftc + rightc;
        int leftbest = root->left ? maxPathSum(root->left):INT_MIN;
        int rightbest = root->right ? maxPathSum(root->right):INT_MIN;
        return max({current , leftbest , rightbest});
    }
};	