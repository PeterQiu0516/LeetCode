/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 */

// @lc code=start
class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int n1 = num1.size(), n2 = num2.size();
        int int1[5100] = {};
        int int2[5100] = {};
        int ans[5101] = {};
        for (int i = 0; i < n1; i++)
        {
            int1[5099 - i] = (int)(num1[n1 - 1 - i] - '0');
        }

        for (int i = 0; i < n2; i++)
        {
            int2[5099 - i] = (int)(num2[n2 - 1 - i] - '0');
        }

        int pass = 0, digit = max(n1, n2);
        for (int i = 5099, j = 0; j < digit; j++)
        {
            ans[i - j + 1] = (pass + int1[i - j] + int2[i - j]) % 10;
            pass = (pass + int1[i - j] + int2[i - j]) / 10;
        }

        if (pass)
            ans[5100 - digit++] = 1;

        string s;
        for (int i = 5100 - digit + 1; i <= 5100; i++)
            s.push_back(char(ans[i] + '0'));
        return s;
    }
};
// @lc code=end
