/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int n1 = s1.size(), n2 = s2.size(), len_remain = n1;
        int count[26] = {};
        for (int i = 0; i < n1; i++)
        {
            count[s1[i] - 'a']++;
        }

        for (int start = 0, end = 0; start < n2 && end < n2 && len_remain; end++)
        {
            // check if current window (start-end) contains each character of s1
            // if len_remain = 0, s1 is found in the window
            if (count[s2[end] - 'a'])
            {
                len_remain--;
                count[s2[end] - 'a']--;
            }

            else
            {
                // count = 0 
                // case 1: did not find the character in s1
                // case 2: there are not so many characters in s1

                // for case 1, start & end adjust to next one, all prev has been recovered.
                // for case 2, there must be repetitions of s2[end], so change start to the pos just after the first s2[end] occurrence since other characters in the window are still valid
                while (s2[start++] != s2[end])
                {
                    // window changed, recover previous deleted characters
                    count[s2[start - 1] - 'a']++;
                    len_remain++;
                }
                // problem occurred for case 2, so do not need to readjust end
                // end = start - 1;
                // cout << "start: " << start << ", end: " << end << " , len" << len_remain << endl;
            }
        }
        // if all characters are found, len_remain = 0;
        return !len_remain;
    }
};
// @lc code=end
