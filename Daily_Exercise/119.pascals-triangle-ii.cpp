/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> ans(rowIndex + 1, 1);
        for (int j = 1; j < ans.size() - 1; j++)
            for (int i = rowIndex - 1; i >= j; i--)
        // C(n,k) = C(n-1,k) + C(n-1,k-1)
                ans[i] = ans[i + 1] + ans[i]; 
        return ans;
    }
};
// @lc code=end
