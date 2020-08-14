/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        unordered_map<char,char> mp={{'(',')'},{'[',']'},{'{','}'}};
        stack<char> tmp;
        for (char c:s)
        {
            switch (c)
            {
            case '(':
            case '[':
            case '{':
                tmp.push(c);
                break;
            case ')':
            case ']':
            case '}':
                if (tmp.empty()||mp[tmp.top()]!=c)
                    return false;
                tmp.pop();
                break;
            }
        }
        return tmp.empty();
    }
};
// @lc code=end
