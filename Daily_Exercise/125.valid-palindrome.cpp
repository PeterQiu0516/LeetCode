/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int begin = 0, end = s.size() - 1;
        int distance = 'a' - 'A';
        while (begin < end)
        {
            while (!is_alpha(s[begin]) && begin < end)
                begin++;
            while (!is_alpha(s[end]) && begin < end)
                end--;
            // check whether they are both numbers or not
            if ((is_num(s[begin]) ^ is_num(s[end])) || (s[begin] != s[end] && s[begin] != s[end] - distance && s[begin] != s[end] + distance))
                return false;
            begin++;
            end--;
        }
        // wrong because this time didn't go back to a character (check whether it is a character)
        // cout << s[begin] <<" " << s[end] << endl;
        return true;
    }

    bool is_alpha(char ch)
    {
        // take care, difference between 0 and P is 26
        return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || is_num(ch));
    }
    bool is_num(char ch)
    {
        return (ch >= '0' && ch <= '9');
    }
};
// @lc code=end
