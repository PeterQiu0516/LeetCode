/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
class Solution
{
    // Manacher sol, O(n)
public:
    int countSubstrings(string s)
    {
        int n = s.size();
        string t = "$#";
        for (const char &c : s)
        {
            t += c;
            t += '#';
        }
        n = t.size();
        t += '!'; // choose 2 different chara at begining and end $ and ! to end the loop

        auto f = vector<int>(n);
        int iMax = 0, rMax = 0, ans = 0; // iMax: center, rMax: right bound
        for (int i = 1; i < n; ++i)
        {
            // f[i]: maximum palindromic radius,
            // i <= rMax, within the interval, min of (difference between rMax and i) and f(j) where i + j = 2iMax
            // i > rMax: new center
            f[i] = (i <= rMax) ? min(rMax - i + 1, f[2 * iMax - i]) : 1;
            // increase radius
            while (t[i + f[i]] == t[i - f[i]])
                ++f[i];
            if (i + f[i] - 1 > rMax)
            {
                iMax = i; // new center
                rMax = i + f[i] - 1; // new rMax
            }
            //  ceil((f[i] - 1) / 2), for abc -> ?#a#b#c#! 2, 2, 2
            ans += (f[i] / 2);
        }

        return ans;
    }

    // dp sol:
    //     vector<vector<int>> dp;

    // public:
    //     int countSubstrings(string s)
    //     {
    //         int len = s.size(), ans = 0;
    //         dp = vector(len, vector(len, 0));

    //         for (int i = 0; i < len; i++)
    //         {
    //             for (int j = len-1; j >= i; j--)
    //             {
    //                 ans += dp_helper(s, i, j) > 0 ? dp_helper(s, i, j) : 0;
    //             }
    //         }
    //         return ans;
    //     }

    //     int dp_helper(string s, int left, int right)
    //     {
    //         if (left < 0 || right >= s.size())
    //             return -1;

    //         if (dp[left][right] < 0) // < 0 : checked but false
    //             return -1;
    //         else if (dp[left][right] == 1)
    //             return 1;

    //         if (left >= right) // 1 character
    //         {
    //             dp[left][right] = 1;
    //             return 1;
    //         }

    //         dp[left][right] = (s[left] == s[right] && dp_helper(s, left + 1, right - 1) > 0) ? 1 : -1;
    //         return dp[left][right];
    //     }
};
// @lc code=end
