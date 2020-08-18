/*
 * @lc app=leetcode id=967 lang=cpp
 *
 * [967] Numbers With Same Consecutive Differences
 */

// @lc code=start
class Solution
{
public:
    vector<int> numsSameConsecDiff(int N, int K)
    {
        vector<int> ans = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
        for (int i = 2; i <= N; ++i) // add new digit for each loop
        {
            vector<int> cur;
            for (auto x : ans) // iterate through all digits
            {
                int y = x % 10;
                if (x == 0) // omit x = 0
                    continue;
                if (K == 0)
                    cur.push_back(x * 10 + y);
                else
                {
                    if (y + K < 10)
                        cur.push_back(x * 10 + y + K);
                    if (y - K >= 0)
                        cur.push_back(x * 10 + y - K);
                }
            }
            ans = cur;
        }
        return ans;
    }
};
// @lc code=end
