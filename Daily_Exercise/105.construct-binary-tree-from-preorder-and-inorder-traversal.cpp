/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    // my raw sol: construct vector many times
    // TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    // {
    //     if (preorder.empty())
    //         return nullptr;

    //     TreeNode *root = new TreeNode(preorder[0]);
    //     if (preorder.size() == 1)
    //         return root;
    //     auto rootIt = find(begin(inorder), end(inorder), preorder[0]);

    //     size_t leftTreeSize = distance(begin(inorder), rootIt);
    //     vector<int> leftPreorder(begin(preorder) + 1, begin(preorder) + 1 + leftTreeSize);
    //     vector<int> leftInorder(begin(inorder), begin(inorder) + leftTreeSize);
    //     root->left = buildTree(leftPreorder, leftInorder);

    //     size_t rightTreeSize = inorder.size() - leftTreeSize - 1;
    //     vector<int> rightPreorder(begin(preorder) + 1 + leftTreeSize, end(preorder));
    //     vector<int> rightInorder(begin(inorder) + 1 + leftTreeSize, end(inorder));
    //     root->right = buildTree(
    //         rightPreorder,
    //         rightInorder);
    //     return root;
    // }

    // using a helper would save memory: do not modifies the 2 array, instead change the search scope
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int startRoot = 0;
        return helper(preorder, inorder, startRoot, 0, inorder.size() - 1);
    }

private:
    TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int &rootIndex, int start, int end)
    {
        if (rootIndex >= preorder.size() || start > end)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[rootIndex]);
        auto pos = distance(inorder.begin(), find(inorder.begin() + start, inorder.begin() + end, preorder[rootIndex]));
        rootIndex++; // for each visit, root get++
        root->left = helper(preorder, inorder, rootIndex, start, pos - 1);
        root->right = helper(preorder, inorder, rootIndex, pos + 1, end);
        return root;
    }
};
// @lc code=end
