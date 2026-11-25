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
    void collectvalues(TreeNode* root , vector<int>& values){
        if(root == nullptr) return;
        collectvalues(root->left , values);
        values.push_back(root->val);
        collectvalues(root->right , values);
    }
    void replacevalues(TreeNode* root , vector<int>& values  , int& index){
        if(!root) return;
        replacevalues(root->left , values , index);
        root->val = values[index++];
        replacevalues(root->right , values , index);
    }
    void recoverTree(TreeNode* root) {
        vector<int> values;
        collectvalues(root , values);
        sort(values.begin() , values.end());
        int index = 0;
        replacevalues(root , values , index);
    }
};