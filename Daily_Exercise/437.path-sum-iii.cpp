/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
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
    // more neat solution:
    int pathSum(TreeNode *root, int sum)
    {
        return root ? pathSum_helper(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum) : 0;
    }

    int pathSum_helper(TreeNode *root, int sum)
    {
        // this only check for paths starting from root
        return root ? (root->val == sum) + pathSum_helper(root->left, sum - root->val) + pathSum_helper(root->right, sum - root->val) : 0;
    }

    // int pathSum(TreeNode *root, int sum)
    // {
    //     int count = 0;
    //     auto tmp = pathSum_helper(root, sum, count);
    //     return count;
    // }

    // vector<int> pathSum_helper(TreeNode *root, int sum, int &count)
    // {
    //     if (!root)
    //         return vector<int>();
    //     vector<int> s;
    //     s.push_back(root->val);
    //     if(root->val == sum) count++;
    //     if (!root->left && !root->right)
    //         return s;
    //     vector<int> left_sum = pathSum_helper(root->left, sum,count);
    //     for (auto it = left_sum.begin(); it != left_sum.end(); it++)
    //     {
    //         *it = *it + root->val;
    //         if (*it == sum)
    //             count++;
    //     }
    //     vector<int> right_sum = pathSum_helper(root->right, sum,count);
    //     for (auto it = right_sum.begin(); it != right_sum.end(); it++)
    //     {
    //         *it = *it + root->val;
    //         if (*it == sum)
    //             count++;
    //     }
    //     s.insert(s.end(), left_sum.begin(), left_sum.end());
    //     s.insert(s.end(), right_sum.begin(), right_sum.end());

    //     return s;
    // }
};
// @lc code=end
