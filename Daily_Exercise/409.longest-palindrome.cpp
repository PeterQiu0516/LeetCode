/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */

// @lc code=start
class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> count;
        for (char c : s)
        {
            if (count.empty() || count.find(c) == count.end())
                count[c] = 1;
            else
                count[c]++;
        }
        int ans = 0, odd_occur = 0;
        for (auto it = count.begin(); it != count.end(); it++)
        {
            if (it->second % 2 == 0)
                ans += it->second;
            else
            {
                odd_occur = 1;
                ans += (it->second - 1);
            }
        }
        return ans + odd_occur;
    }
};
// @lc code=end
