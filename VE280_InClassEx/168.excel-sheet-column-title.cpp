/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */

// @lc code=start
class Solution
{
public:
    string convertToTitle(int n)
    {
        return n == 0 ? "" : convertToTitle((n-1) / 26) + (char)((n-1)% 26+ 'A');
    }
};
// @lc code=end
