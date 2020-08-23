/*
 * @lc app=leetcode id=201 lang=cpp
 *
 * [201] Bitwise AND of Numbers Range
 */

// @lc code=start
class Solution
{
public:
    // bitwiseAnd of series of num, final digits will always be 0 if n > m
    // finally we get the rest digits at front to be n = m, and bitwiseAnd of them is still this

    // Brian Kernighan
    // n & (n-1) will eliminate the lasting ones of n
    // this can help skip eliminating the 0 digits in n (only eliminate 1)
    int rangeBitwiseAnd(int m, int n)
    {
        return (n > m) ? (rangeBitwiseAnd(m, n&(n-1))) : n;
    }

    // // basic elimination
    // int rangeBitwiseAnd(int m, int n)
    // {
    //     return (n > m) ? (rangeBitwiseAnd(m >> 1, n >> 1) << 1) : m;
    // }
};
// @lc code=end
