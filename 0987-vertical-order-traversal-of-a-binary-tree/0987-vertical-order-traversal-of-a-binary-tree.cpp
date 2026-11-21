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
private:
    void dfs(TreeNode* node, int row, int column, vector<tuple<int, int, int>>& nodes ){
        if (node == nullptr)
            return;
        nodes.push_back({ column, row, node->val });
        dfs( node->left, row + 1, column - 1, nodes );
        dfs( node->right, row + 1, column + 1, nodes );
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root){
        if (root == nullptr)
            return {};
        vector<tuple<int, int, int>> nodes;
        dfs(root, 0, 0, nodes);
        sort(nodes.begin(), nodes.end());
        vector<vector<int>> answer;
        int previousColumn = INT_MIN;
        for (auto& entry : nodes) {
            auto [column, row, value] = entry;
            if (column != previousColumn) {
                answer.push_back({});
                previousColumn = column;
            }
            answer.back().push_back(value);
        }
        return answer;
    }
};