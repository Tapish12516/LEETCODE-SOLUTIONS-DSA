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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> answer;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while(curr!= nullptr || !st.empty()){
            while(curr!=nullptr){
                if(curr->right) st.push(curr->right);
                st.push(curr);
                curr = curr->left;
            }
            if(!st.empty()){
                curr = st.top();
                st.pop();
                if(curr->right!=nullptr && !st.empty() && st.top() == curr->right){
                    st.pop();  st.push(curr);  curr = curr->right;
                }
                else {
                    answer.push_back(curr->val);
                    curr = nullptr;
                }
            }
        }
        return answer;
    }
};

//     void postorder(TreeNode* node , vector<int>& answer){
//         if(!node) return;
//         postorder(node->left , answer);
//         postorder(node->right , answer);
//         answer.push_back(node->val);
//     }
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> answer;
//         postorder(root , answer);
//         return answer;