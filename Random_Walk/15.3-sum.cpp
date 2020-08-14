/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();

        vector<vector<int>> ans;

        unordered_map<int, int> counts;
        // for counting occurrence of each int
        unordered_map<int, int> one_sum;
        // for measuring index, to avoid using the same element twice

        // initialize
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                counts[-(nums[i] + nums[j])] = 0;
            }
        }

        // // generate the map for one_sum
        for (int i = 0; i < n; i++)
        {
            one_sum[nums[i]] = i;
            if (counts.count(nums[i]) == 0)
            {
                counts[nums[i]] = 1;
            }
            else
            {
                counts[nums[i]]++;
            }
        }

        set<vector<int>> all_ans;

        // 0 occurs 3 times
        if (counts[0] >= 3)
            ans.push_back({0, 0, 0});

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (counts[-(nums[i] + nums[j])] == 0)
                {
                    // no such 3 sums
                    continue;
                }
                if (nums[i] == 0 && nums[j] == 0)
                {
                    continue;
                }
                if (i != one_sum[-(nums[i] + nums[j])] && j != one_sum[-(nums[i] + nums[j])])
                {
                    // did not use the same element twice
                    vector<int> single_ans = {nums[i], nums[j], -(nums[i] + nums[j])};
                    sort(single_ans.begin(), single_ans.end());
                    all_ans.insert(single_ans);
                }
            }
        }

        for (set<vector<int>>::iterator itx = all_ans.begin(); itx != all_ans.end(); itx++)
        {
            vector<int> single_ans;
            ans.push_back((*itx));
        }

        return ans;
    }
};
// @lc code=end
