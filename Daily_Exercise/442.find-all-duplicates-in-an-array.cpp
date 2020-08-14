/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            // -1: occurred once
            // -2: occurred twice
            if (nums[i] < 0)
                continue;
            while (nums[i] > 0)
            {
                // if nums[nums[i] - 1] <=0, all points has been marked
                if (nums[i] != i + 1) // does not point to itself
                {
                    if (nums[nums[i] - 1] <= 0) // points to 0 or -1
                    {
                        nums[nums[i] - 1] = nums[nums[i] - 1] == 0 ? -1 : -2;
                        nums[i] = 0;
                    }
                    else // points to positive num
                    {
                        int tmp = nums[nums[i] - 1];
                        nums[nums[i] - 1] = -1;
                        nums[i] = tmp;
                    }
                }
                else // points to itself
                {
                    nums[i] = -1;
                    break;
                }
            }
        }
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == -2)
                ans.push_back(i + 1);
        }
        return ans;
    }
};
// @lc code=end
