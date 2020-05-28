/*
 * @lc app=leetcode id=771 lang=cpp
 *
 * [771] Jewels and Stones
 */

// @lc code=start
class Solution
{
public:
    int numJewelsInStones(string J, string S)
    {
        unordered_map<char, int> Count;
        for (auto s : S)
        {
            Count[s]++;
        }

        int res = 0;
        for (auto j : J)
        {
            res += Count[j];
        }
        return res;
    }
};
// @lc code=end
