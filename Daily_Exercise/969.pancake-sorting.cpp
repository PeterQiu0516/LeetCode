/*
 * @lc app=leetcode id=969 lang=cpp
 *
 * [969] Pancake Sorting
 */

// @lc code=start
class Solution
{
public:
    vector<int> pancakeSort(vector<int> A)
    {
        vector<int> res;
        int x, i;
        // start from A.size() to 1;
        for (x = A.size(); x > 0; --x)
        {
            for (i = 0; A[i] != x; ++i){}
            reverse(A.begin(), A.begin() + i + 1);
            // put x at A[0]
            res.push_back(i + 1);
            reverse(A.begin(), A.begin() + x);
            // put x at A[x-1]
            res.push_back(x);
        }
        return res;
    }
};
// @lc code=end
