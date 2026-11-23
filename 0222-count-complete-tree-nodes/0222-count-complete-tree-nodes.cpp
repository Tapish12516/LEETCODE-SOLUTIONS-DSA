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
    int getrighth(TreeNode* node){
        int h = 0;
        while(node != nullptr){
            h++;
            node = node->right;
        }
        return h;
    }
    int getlefth(TreeNode* node){
        int h = 0;
        while(node != nullptr){
            h++;
            node = node->left;
        }
        return h;
    }
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        int lh = getlefth(root);
        int rh = getrighth(root);
        if(lh == rh) return (1LL << lh) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

        // if (root == nullptr)
        //     return 0;
        // int leftCount = countNodes(root->left);          //standard dfs approach
        // int rightCount = countNodes(root->right);
        // return 1 + leftCount + rightCount;