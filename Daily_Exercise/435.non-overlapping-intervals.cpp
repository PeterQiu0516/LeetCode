/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &i1, const vector<int> &i2) { return i1[0] < i2[0]; });
        int ans = 0, pre = 0;
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < intervals[pre][1])
            {
                ans++;
                // update intervals
                if (intervals[i][1] < intervals[pre][1])
                    pre = i;
            }
            else
                pre = i;
        }
        return ans;
    }
};
// @lc code=end
