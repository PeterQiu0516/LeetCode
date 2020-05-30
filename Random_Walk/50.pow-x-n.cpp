/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == 0)
            return 1;
        double ans = 1;
        int sign = 1;
        double multiplier = x;
        if (n < 0)
        {
            if (n == (1 << 31))
            {
                for (int i = 0; i < 31; i++)
                {
                    multiplier *= multiplier;
                }
                return 1.0 / multiplier;
            }
            sign = 0;
            n = -n;
        }
        while (n)
        {
            if (n & 1)
                ans *= multiplier;
            multiplier *= multiplier;
            n >>= 1;
        }
        if (!sign)
            return 1.0 / ans;
        return ans;
    }
};
// @lc code=end
