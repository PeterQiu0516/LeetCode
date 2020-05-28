/*
 * @lc app=leetcode id=1200 lang=cpp
 *
 * [1200] Minimum Absolute Difference
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> res;
        vector<int> diff;
        for (int i = 0; i < arr.size() - 1; i++)
            diff.push_back(arr[i+1] - arr[i]);
        int min_diff = *min_element(diff.begin(),diff.end());
        for (int i = 0; i < diff.size(); i++)
            if(diff[i] == min_diff)
                res.push_back({arr[i],arr[i+1]});
        return res;
    }
};
// @lc code=end

