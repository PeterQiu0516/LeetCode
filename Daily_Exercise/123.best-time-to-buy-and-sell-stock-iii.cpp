/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
class Solution
{
    vector<vector<vector<int>>> dp;

public:
    // neat solution
    int maxProfit(vector<int> &prices)
    {
        int profitFirst = 0;
        int profitSecond = 0;
        int priceFirst = INT_MAX;
        int priceSecond = INT_MAX;
        for (int i = 0; i < prices.size(); i++)
        {
            priceFirst = min(priceFirst, prices[i]);
            profitFirst = max(profitFirst, prices[i] - priceFirst);
            priceSecond = min(priceSecond, prices[i] - profitFirst); // we have already earned profitFirst
            profitSecond = max(profitSecond, prices[i] - priceSecond);
        }

        return profitSecond;
    }

    // dp solution
    // int maxProfit(vector<int> &prices)
    // {
    //     int size = prices.size();
    //     dp = vector<vector<vector<int>>>(3, vector<vector<int>>(size, vector<int>(size, 0)));
    //     if (prices.size() <= 1)
    //         return 0;
    //     return dp_helper(prices, 2, 0, size - 1);
    // }

    // int dp_helper(vector<int> &prices, int i, int j, int k)
    // {
    //     // i: chances remain
    //     // j: left bound for current interval
    //     // k: right bound for current interval

    //     if (i == 0 || j >= prices.size() - 1 || k >= prices.size() || j >= k)
    //         return 0;

    //     if (dp[i][j][k])
    //         return dp[i][j][k];

    //     if (k == j + 1) // [1, 2, 4], 2&4 with 2 chances is equival = 1 chances
    //     {
    //         dp[i][j][k] = prices[k] - prices[j] > 0 ? prices[k] - prices[j] : 0;
    //         return dp[i][j][k];
    //     }

    //     if (i == 1) // only one chances remains, find the largest return in this interval
    //     {
    //         // iterate through all j for given interval
    //         int min = prices[j];
    //         for (int tmp_j = j; tmp_j < k; tmp_j++)
    //         {
    //             if (prices[tmp_j] > min) // since the max will only become smaller [2,8,0,3,9]
    //                 continue;
    //             else
    //                 min = prices[tmp_j];

    //             int max = prices[tmp_j + 1];
    //             // find the largest return for fixed j and given k
    //             for (int t = tmp_j + 1; t <= k; t++)
    //                 max = prices[t] > max ? prices[t] : max;
    //             dp[i][tmp_j][k] = max - min > dp[i][tmp_j][k] ? max - min : dp[i][tmp_j][k];
    //             dp[i][tmp_j][k] = max - min > dp[i][tmp_j][k] ? max - min : dp[i][tmp_j][k];
    //         }
    //     }
    //     else // 2 chances remains, dp switch
    //     {
    //         // 1 sale in the whole interval
    //         dp[1][j][k] = dp_helper(prices, 1, j, k);
    //         dp[2][j][k] = dp[1][j][k] > dp[2][j][k] ? dp[1][j][k] : dp[2][j][k];

    //         // iterate through all choice of k (cut the intervals)
    //         for (int tmp_k = j; tmp_k < k; tmp_k++) // starting from j, for [2,1,4]
    //         {
    //             // 2 sales in the same interval
    //             dp[2][j][tmp_k] = dp_helper(prices, 2, j, tmp_k);
    //             dp[2][tmp_k + 1][k] = dp_helper(prices, 2, tmp_k + 1, k);
    //             // 1 sale in each interval
    //             dp[1][j][tmp_k] = dp_helper(prices, 1, j, tmp_k);
    //             dp[1][tmp_k + 1][k] = dp_helper(prices, 1, tmp_k + 1, k);

    //             int ans_k = max(dp[1][j][tmp_k] + dp[1][tmp_k + 1][k], max(dp[2][j][tmp_k], dp[2][tmp_k + 1][k]));
    //             dp[2][j][k] = ans_k > dp[i][j][k] ? ans_k : dp[i][j][k];
    //         }
    //     }

    //     return dp[i][j][k];
    // }
};
// @lc code=end
