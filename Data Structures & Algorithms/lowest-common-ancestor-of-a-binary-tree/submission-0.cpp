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
        if (!root) return nullptr;
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> queue;
        parent[root] = nullptr;
        queue.push(root);
        
        while(!parent.count(p) || !parent.count(q)) {
            TreeNode* node = queue.front();
            queue.pop();
            if (node->left) {
                queue.push(node->left);
                parent[node->left] = node;
            }
            if (node->right) {
                queue.push(node->right);
                parent[node->right] = node;
            }
        }

        unordered_set<TreeNode*> ancestor;
        while (p) {
            ancestor.insert(p);
            p = parent[p];
        }

        while (!ancestor.count(q)) {
            q = parent[q];
        }

        return q;

    }
};