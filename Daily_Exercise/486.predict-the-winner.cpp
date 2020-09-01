/*
 * @lc app=leetcode id=486 lang=cpp
 *
 * [486] Predict the Winner
 */

// @lc code=start
class Solution
{
public:
    bool PredictTheWinner(vector<int> &nums)
    {
        int len = nums.size();
        auto dp = vector<vector<int>>(len, vector<int>(len));
        // dp[i][j]: largest score difference of current player against next player if the rest interval is from i to j
        for (int i = 0; i < len; i++)
        {
            dp[i][i] = nums[i];
        }

        for (int i = len - 2; i >= 0; i--)
        {
            for (int j = i + 1; j < len; j++)
            {
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }
        return dp[0][len - 1] >= 0;
    }
};

// @lc code=end
