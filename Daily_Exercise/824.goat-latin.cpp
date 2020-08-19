/*
 * @lc app=leetcode id=824 lang=cpp
 *
 * [824] Goat Latin
 */

// @lc code=start
class Solution
{
public:
    string toGoatLatin(string S)
    {
        stringstream ss(S);
        stringstream ans_ss;
        string word;
        int count = 1;
        while (ss >> word)
        {
            if (word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u' || word[0] == 'A' || word[0] == 'E' || word[0] == 'I' || word[0] == 'O' || word[0] == 'U')
                ans_ss << word << "ma" << string(count++, 'a') << " ";
            else
            {
                ans_ss << word.substr(1, word.size() - 1) << word.substr(0, 1) << "ma" << string(count++, 'a') << " ";
            }
        }
        string ans = ans_ss.str();
        ans = ans.substr(0, ans.size() - 1); // eliminate ending space
        return ans;
    }
};
// @lc code=end
