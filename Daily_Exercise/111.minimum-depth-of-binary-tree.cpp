/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;
        int left_height = (!root->left) ? INT_MAX : minDepth(root->left);
        int right_height = (!root->right) ? INT_MAX : minDepth(root->right);
        return 1 + min(left_height, right_height);
    }
};
// @lc code=end
