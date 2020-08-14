/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 */

// @lc code=start
class Solution
{
public:
    bool isPowerOfFour(int num)
    {
        // meaningless boundaries cases
        if (num <= 0)
            return false;
        double l = log(num) / log(4);
        return abs(l - double((int)l)) < 10e-6;
    }
};
// @lc code=end
