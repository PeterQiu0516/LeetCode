/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return root;
        if (root->val > key)
            root->left = deleteNode(root->left, key);
        else if (root->val < key)
            root->right = deleteNode(root->right, key);
        else
        {
            if (!root->left)
            {
                TreeNode *right = root->right;
                delete root;
                return right;
            }
            else if (!root->right)
            {
                TreeNode *left = root->left;
                delete root;
                return left;
            }
            else
            {
                TreeNode *tmp = root->right;
                while (tmp->left)
                    tmp = tmp->left;
                root->val = tmp->val;
                root->right = deleteNode(root->right, tmp->val);
            }
        }
        return root;
    }

    // do not use iteration, it is difficult to delete a node iteratively
    // TreeNode *deleteNode(TreeNode *root, int key)
    // {
    //     TreeNode *tmp = root;
    //     while (tmp->val != key && tmp)
    //         tmp = (tmp->val < key) ? tmp->right : tmp->left;
    //     if (tmp)
    //     {
    //         TreeNode *curr = tmp;
    //         if (tmp->left && tmp->right)
    //         {
    //             TreeNode *currLeft = tmp->left;
    //             tmp = tmp->right;
    //             while (tmp->left)
    //                 tmp = tmp->left;
    //             tmp->left = currLeft;
    //             // delete currLeft;
    //         }
    //         else if (tmp->left)
    //             tmp = tmp->left;
    //         else if (tmp->right)
    //             tmp = tmp->right;
    //         delete curr;
    //     }
    //     return root;
    // }
};
// @lc code=end
