/*
 * @lc app=leetcode id=412 lang=cpp
 *
 * [412] Fizz Buzz
 */

// @lc code=start
class Solution
{
    vector<string> ans;

public:
    vector<string> fizzBuzz(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            bool modThree = i % 3 == 0;
            bool modFive = i % 5 == 0;

            if (modThree && modFive)
            {
                ans.push_back("FizzBuzz");
            }
            else if (modThree)
            {
                ans.push_back("Fizz");
            }
            else if (modFive)
            {
                ans.push_back("Buzz");
            }
            else
            {
                ans.push_back(to_string(i));
            }
        }
        return ans;
    }
};
// @lc code=end
