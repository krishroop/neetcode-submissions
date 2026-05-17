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

    int ans = INT_MIN;

    int dfs(TreeNode* node) {

        if (!node)
            return 0;

        // maximum gain from left subtree
        int left =
            max(0, dfs(node->left));

        // maximum gain from right subtree
        int right =
            max(0, dfs(node->right));

        // path passing through current node
        int currPath =
            left +
            node->val +
            right;

        // update global answer
        ans = max(ans, currPath);

        // return best single path upward
        return node->val +
               max(left, right);
    }

    int maxPathSum(TreeNode* root) {

        dfs(root);

        return ans;
    }
};
