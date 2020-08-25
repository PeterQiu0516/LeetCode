/*
 * @lc app=leetcode id=491 lang=cpp
 *
 * [491] Increasing Subsequences
 */

// @lc code=start
class Solution {
public:
    vector<int> temp; 
    vector<vector<int>> ans;

    void dfs(int cur, int last, vector<int>& nums) {
        if (cur >= nums.size()) // end dfs
        {
            if (temp.size() >= 2) 
                ans.push_back(temp);
            return;
        }
        if (nums[cur] >= last) // greater, select
        {
            temp.push_back(nums[cur]); // add nums[cur]
            dfs(cur + 1, nums[cur], nums); // further dfs
            temp.pop_back(); // delete nums[cur]
        }

        // avoid repetition: if num[cur] == last, we don't visit dfs(cur + 1, last, nums) for 2 times.
        if (nums[cur] != last) // go to next position
            dfs(cur + 1, last, nums);
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(0, INT_MIN, nums);
        return ans;
    }
};

// @lc code=end

