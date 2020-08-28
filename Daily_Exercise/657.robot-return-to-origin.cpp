/*
 * @lc app=leetcode id=657 lang=cpp
 *
 * [657] Robot Return to Origin
 */

// @lc code=start
class Solution
{
public:
    bool judgeCircle(string moves)
    {
        if (moves.empty())
            return true;
        int l = 0, r = 0, u = 0, d = 0;
        for (int i = 0; i < moves.size(); i++)
        {
            switch (moves[i])
            {
            case 'L':
                l++;
                break;
            case 'R':
                r++;
                break;
            case 'U':
                u++;
                break;
            case 'D':
                d++;
                break;
            }
        }
        if (l != r || u != d)
            return false;
        return true;
    }
};
// @lc code=end
