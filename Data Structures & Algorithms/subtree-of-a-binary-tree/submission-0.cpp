/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullroottr), right(nullroottr) {}
 *     TreeNode(int x) : val(x), left(nullroottr), right(nullroottr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
    if(!p && !q) return true;
    if(!p || !q || p->val != q->val) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if(!root) return !subRoot;
    
    // Check if root is the same as subRoot
    if(isSameTree(root, subRoot)) return true;
    
    // Check if subRoot is in left or right subtree of root
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}
};
