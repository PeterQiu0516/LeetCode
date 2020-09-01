/*
 * @lc app=leetcode id=877 lang=cpp
 *
 * [877] Stone Game
 */

// @lc code=start
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        // rank by odd/even
        return true;
    }
};

// // dp sol
// class Solution
// {
// public:
//     bool stoneGame(vector<int> &piles)
//     {
//         int len = piles.size();
//         auto dp = vector<vector<int>>(len, vector<int>(len));
//         // dp[i][j]: largest score difference of current player against next player if the rest interval is from i to j
//         for (int i = 0; i < len; i++)
//         {
//             dp[i][i] = piles[i];
//         }

//         for (int i = len - 2; i >= 0; i--)
//         {
//             for (int j = i + 1; j < len; j++)
//             {
//                 dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
//             }
//         }
//         return dp[0][len - 1] >= 0;
//     }
// };
// @lc code=end

