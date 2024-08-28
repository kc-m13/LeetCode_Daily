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
    
    bool isSameTree(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true; // Both are null
        if (!s || !t) return false; // One is null and the other is not
        if (s->val != t->val) return false; // Values differ

        // Recursively check left and right subtrees
        return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
    }
    
public:        

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false; // Reached the end of the tree
        if (isSameTree(root, subRoot)) return true; // Check if current trees are identical

        // Recursively check left and right subtrees
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};