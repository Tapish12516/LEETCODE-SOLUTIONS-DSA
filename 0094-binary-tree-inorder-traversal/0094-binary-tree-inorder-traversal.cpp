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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        TreeNode* curr = root;
        while( curr != nullptr || !st.empty() ){
            while(curr != nullptr){
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            ans.push_back(curr->val);
            curr = curr->right;
        }
        return ans;
    }
};


//     void inorder(TreeNode* node , vector<int>& answer){
//         if(!node) return;
//         inorder(node->left,answer);
//         answer.push_back(node->val);
//         inorder(node->right,answer);
//     }
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> answer;
//         inorder(root , answer);
//         return answer;
//     }