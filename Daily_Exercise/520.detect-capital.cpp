/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 */

// @lc code=start
class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int capital_num = 0;
        for (char ch : word)
            capital_num += is_captial(ch);
        return ((capital_num == 0) || (capital_num == word.size()) || (capital_num == 1 && is_captial(word[0])));
    }

    bool is_captial(char ch)
    {
        return (ch >= 'A' && ch <= 'Z');
    }
};
// @lc code=end
