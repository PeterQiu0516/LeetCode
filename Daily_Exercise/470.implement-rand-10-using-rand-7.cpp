/*
 * @lc app=leetcode id=470 lang=cpp
 *
 * [470] Implement Rand10() Using Rand7()
 */

// @lc code=start
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution
{
public:
    int rand10()
    {
        while (true)
        {
            // 0 - 48
            int rand40 = (rand7() - 1) * 7 + rand7() - 1;
            if (rand40 < 40)
                return rand40 % 10 + 1;
            // rest: 0 - 8
            int rest = rand40 % 10;
            int rand63 = rest * 7 + rand7() - 1; // 0 - 62
            if (rand63 < 60)
                return rand63 % 10 + 1;

            // rest: 0-2
            rest = rand63 % 10;
            int rand21 = rest * 7 + rand7() - 1; // 0-20
            if (rand21 < 20)
                return rand21 % 10 + 1;
            // rest: 0, useless
        }
    }
};
// @lc code=end
