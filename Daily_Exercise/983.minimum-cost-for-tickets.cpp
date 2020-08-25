/*
 * @lc app=leetcode id=983 lang=cpp
 *
 * [983] Minimum Cost For Tickets
 */

// @lc code=start
class Solution
{
    vector<int> dp;

public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        if (costs[0] * 7 <= costs[1] && costs[0] * 30 <= costs[2])
            return days.size() * costs[0];
        dp = vector<int>(days.size(), 0);
        return dfs(0, days, costs);
    }

    int dfs(int curr, vector<int> &days, vector<int> &costs)
    {
        if (curr >= days.size()) // end iteration
            return 0;
        if (dp[curr] > 0)
            return dp[curr];
        int ans = dfs(curr + 1, days, costs) + costs[0];
        int seven_pos = lower_bound(days.begin() + curr, curr + 7 >= days.size() ? days.end() : days.begin() + curr + 7, days[curr] + 7) - days.begin(); // for seven dates, the time period must be >= 7 days
        ans = min(ans, dfs(seven_pos, days, costs) + costs[1]);
        int thirty_pos = lower_bound(days.begin() + curr, curr + 30 >= days.size() ? days.end() : days.begin() + curr + 30, days[curr] + 30) - days.begin(); // for 30 dates, the time period must be >= 30 days
        ans = min(ans, dfs(thirty_pos, days, costs) + costs[2]);
        dp[curr] = ans;
        return ans;
    }
};
// @lc code=end
