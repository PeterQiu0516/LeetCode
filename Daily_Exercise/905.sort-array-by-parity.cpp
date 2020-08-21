/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
 */

// @lc code=start
class Solution
{
public:
    // O(n) & no extra space
    vector<int> sortArrayByParity(vector<int> &A)
    {
        int end = A.size() - 1;
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] % 2 == 0)
                continue;
            while (A[i] % 2 == 1 && end > i)
            {
                int tmp = A[end];
                A[end--] = A[i];
                A[i] = tmp;
            }
        }
        return A;
    }
};
// @lc code=end
