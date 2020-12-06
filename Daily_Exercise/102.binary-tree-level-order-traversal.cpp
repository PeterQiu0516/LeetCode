/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (root == nullptr)
            return result;
        queue<TreeNode *> q;
        size_t levelCount = 1, depth = 0;
        q.push(root);
        result.push_back(vector<int>());
        result[depth].reserve(levelCount);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            result[depth].push_back(node->val);
            levelCount--;
            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
            if (levelCount == 0 && !q.empty())
            {
                depth++;
                levelCount = q.size();
                result.push_back(vector<int>());
                result[depth].reserve(levelCount);
            }
        }
        return result;
    }
};
// @lc code=end
