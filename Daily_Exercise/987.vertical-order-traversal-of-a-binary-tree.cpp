/*
 * @lc app=leetcode id=987 lang=cpp
 *
 * [987] Vertical Order Traversal of a Binary Tree
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
    struct Node
    {
        int val;
        int height;
    };

    // bool Node_cmp(Node node1, Node node2)
    // {
    //     if (node1.height == node2.height)
    //         return node1.val < node2.val;
    //     return node1.height < node2.height;
    // }

    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<Node>> tmp(1000, vector<Node>());
        vector<vector<int>> ans;
        verticalTraversal_helper(root, tmp, 500, 0);

        for (int i = 0; i < tmp.size(); i++)
        {
            if (tmp[i].size())
            {
                sort(tmp[i].begin(), tmp[i].end(), [](Node n1, Node n2) { return n1.height == n2.height ? n1.val < n2.val : n1.height < n2.height; });
                vector<int> tmp_arr;
                for (int j = 0; j < tmp[i].size(); j++)
                {
                    tmp_arr.push_back(tmp[i][j].val);
                }
                ans.push_back(tmp_arr);
            }
        }
        return ans;
    }

    void verticalTraversal_helper(TreeNode *root, vector<vector<Node>> &ans, int pos, int height)
    {
        if (!root)
            return;
        Node n = {root->val, height};
        ans[pos].push_back(n);
        verticalTraversal_helper(root->left, ans, pos - 1, height + 1);
        verticalTraversal_helper(root->right, ans, pos + 1, height + 1);
    }
};

// @lc code=end
