/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution
{
public:
    string tmp;
    vector<string> res;
    vector<string> phone = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void dfs(int pos, string digits)
    {
        if (pos == digits.size()) // end recursion
        {
            res.push_back(tmp);
            return;
        }
        int num = digits[pos] - '0';
        for (int i = 0; i < phone[num].size(); i++)
        {
            tmp.push_back(phone[num][i]);
            dfs(pos + 1, digits);
            tmp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return res;
        dfs(0, digits);
        return res;
    }
};

// @lc code=end
