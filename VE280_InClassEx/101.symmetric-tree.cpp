/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 */

// @lc code=start
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
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        return isSymmetric_helper(root, root);
    }
    
    bool isSymmetric_helper(TreeNode *left, TreeNode *right)
    {
        // null case
        if (!left && !right)
            return true;
        if (!left || !right)
            return false;
        // recur case
        if (left->val == right->val)
            return isSymmetric_helper(left->left, right->right) && isSymmetric_helper(left->right, right->left);
        return false;
    }
};
// @lc code=end
