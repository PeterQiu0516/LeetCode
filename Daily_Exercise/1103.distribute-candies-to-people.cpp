/*
 * @lc app=leetcode id=1103 lang=cpp
 *
 * [1103] Distribute Candies to People
 */

// @lc code=start
class Solution
{
public:
    vector<int> distributeCandies(int candies, int num_people)
    {
        // 2k>= n^2+n, take sqrt(2k) to approximate num_distri
        int num_distri = (int)sqrt(candies * 2);
        if (num_distri * (num_distri + 1) / 2 > candies) // sqrt(n^2+n)-sqrt(n) < 1
            num_distri--;
        int num_round = num_distri / num_people;
        int num_distri_left = num_distri % num_people;

        vector<int> ans(num_people, 0);
        for (int i = 0; i < num_people; i++)
        {
            int this_num_round = num_round + int(num_distri_left >= (i + 1)); // one more round
            ans[i] = (i + 1) * this_num_round + num_people * (this_num_round - 1) * this_num_round / 2;
            candies -= ans[i];
        }

        if (candies)
            ans[num_distri_left] += candies;

        return ans;
    }
};
// @lc code=end
