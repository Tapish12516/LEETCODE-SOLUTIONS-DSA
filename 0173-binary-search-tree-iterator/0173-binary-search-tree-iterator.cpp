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
class BSTIterator {
public:
    stack<TreeNode*> s;
    void pushallleft(TreeNode* node){
        while(node!=nullptr){
            s.push(node);
            node = node->left;
        }
    }
    BSTIterator(TreeNode* root) {
        pushallleft(root);
    }
    int next() {
        TreeNode* topnode = s.top();
        s.pop();
        if(topnode->right != nullptr){
            pushallleft(topnode->right);
        }
        return topnode->val;
    }
    bool hasNext() {
        return !s.empty();
    }
};


    // vector<int> sortednodes;
    // int index;
    // void inorder(TreeNode* root){
    //     if (root == nullptr) {
    //         return;
    //     }
    //     inorder(root->left);
    //     sortednodes.push_back(root->val);
    //     inorder(root->right);
    // }
    // BSTIterator(TreeNode* root) {
    //     index = 0;
    //     inorder(root);
    // }
    // int next() {                                    //bruteforce approach O(N) both TC and SC
    //     int value = sortednodes[index++];
    //     return value;
    // }
    // bool hasNext() {
    //     return index < sortednodes.size();
    // }


/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */