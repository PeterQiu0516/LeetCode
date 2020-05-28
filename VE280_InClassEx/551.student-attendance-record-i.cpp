/*
 * @lc app=leetcode id=551 lang=cpp
 *
 * [551] Student Attendance Record I
 */

// @lc code=start
class Solution
{
public:
    bool checkRecord(string s)
    {
        int count_A = 0;
        int count_L = 0;
        int L = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'A')
                count_A++;
            if (L == 0)
            {
                if ((count_L == 0 || count_L == 1) && s[i] == 'L')
                {
                    count_L++;
                }
                else if (count_L == 2 && s[i] == 'L')
                {
                    L = 1;
                }
                else if(s[i] != 'L')
                    count_L = 0;
            }
        }
        if (L || count_A >= 2)
            return false;
        return true;
    }
};
// @lc code=end
