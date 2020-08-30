/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */

// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        stringstream ss(s), ans;
        string word;
        while (ss >> word)
        {
            reverse(word.begin(), word.end());
            ans << word;
            ans << " ";
        }
        string res = ans.str();
        return res.substr(0, res.size() - 1); // eliminate ending space
    }
};
// @lc code=end
