/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    // bottom-up recursion, O(n)
    bool isBalanced(TreeNode *root)
    {
        if (!root)
            return true;
        return height(root) != -1;
    }

    int height(TreeNode *root)
    {

        if (!root)
            return 0;
        int leftHeight, rightHeight;
        // Mark those unbalance tree and there precedent with -1
        if ((leftHeight = height(root->left)) == -1 || (rightHeight = height(root->right)) == -1 || abs(leftHeight - rightHeight) > 1)
            return -1;
        return max(leftHeight, rightHeight) + 1;
    }

    // // basic top-down recursion, O(n^2), calculate height multiple times
    // bool isBalanced(TreeNode *root)
    // {
    //     if (!root)
    //         return true;
    //     return isBalanced(root->left) && isBalanced(root->right) && abs(height(root->left) - height(root->right)) <= 1;
    // }

    // int height(TreeNode *root)
    // {
    //     if (!root)
    //         return 0;
    //     return max(height(root->left), height(root->right)) + 1;
    // }
};
// @lc code=end
