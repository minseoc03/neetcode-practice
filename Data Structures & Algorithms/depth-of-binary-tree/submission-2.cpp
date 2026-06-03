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
    int maxDepth(TreeNode* root) {
        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});
        int max_depth = 0;

        while(!st.empty()) {
            pair<TreeNode*, int> curr = st.top();
            st.pop();
            TreeNode* node = curr.first;
            int depth = curr.second;
            if (node != nullptr) {
                max_depth = max(max_depth, depth);
                st.push({node->left, depth + 1});
                st.push({node->right, depth + 1});
            }
        }
        return max_depth;
    }
};
