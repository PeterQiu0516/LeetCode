/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */

// @lc code=start
class Solution
{
public:
    int titleToNumber(string s)
    {
        reverse(s.begin(), s.end());
        int ans = 0;
        for (int digit = 0; digit < s.size(); digit++)
        {
            ans += (s[digit] - 'A' + 1) * pow(26, digit);
        }
        return ans;
    }
};
// @lc code=end
