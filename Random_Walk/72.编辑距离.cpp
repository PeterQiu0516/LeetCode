/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution
{
    vector<vector<int>> dp;
    string word1;
    string word2;

public:
    int minDistance(string word1, string word2)
    {
        dp = vector<vector<int>>(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        this->word1 = word1;
        this->word2 = word2;
        return minDistanceHelper(word1.size(), word2.size());
    }

    int minDistanceHelper(int m, int n)
    {
        if (m == 0)
            return n;
        if (n == 0)
            return m;
        if (dp[m][n] != 0)
            return dp[m][n];
        if (word1[m - 1] == word2[n - 1])
        {
            dp[m][n] = minDistanceHelper(m - 1, n - 1);
            return dp[m][n];
        }
        int ans = min(1 + minDistanceHelper(m - 1, n), 1 + minDistanceHelper(m, n - 1));
        ans = min(ans, 1 + minDistanceHelper(m - 1, n - 1));
        dp[m][n] = ans;
        return ans;
    }
};
// @lc code=end
