/*
 * @lc app=leetcode id=436 lang=cpp
 *
 * [436] Find Right Interval
 */

// @lc code=start
class Solution
{
public:
    // map sol:
    vector<int> findRightInterval(vector<vector<int>> &intervals)
    {
        vector<int> ans(intervals.size());
        map<int, int> m;
        for (int i = 0; i < intervals.size(); i++)
            m[intervals[i][0]] = i;
        for (int i = 0; i < intervals.size(); i++)
            ans[i] = m.lower_bound(intervals[i][1]) != end(m) ? m.lower_bound(intervals[i][1])->second : -1;
        return ans;
    }

    // vector<int> findRightInterval(vector<vector<int>> &intervals)
    // {
    //     // sort(intervals.begin(),intervals.end(),[](vector<int> a, vector<int>b){return a[0]<b[0];})
    //     // if(intervals[0][0])
    //     // int prevRight = intervals[0][0];
    //     // int nextLeft = intervals[]
    //     vector<int> ans(intervals.size(), -1);

    //     if (intervals.size() == 1)
    //         return ans;
    //     vector<vector<int>> left;
    //     vector<vector<int>> right;
    //     for (int i = 0; i < intervals.size(); i++)
    //     {
    //         left.push_back({intervals[i][0], i});
    //         right.push_back({intervals[i][1], i});
    //     }

    //     sort(left.begin(), left.end(), [](vector<int> a, vector<int> b) { return a[0] < b[0]; });
    //     sort(right.begin(), right.end(), [](vector<int> a, vector<int> b) { return a[0] < b[0]; });

    //     int currLeft = 0;
    //     for (int i = 0; i < intervals.size(); i++)
    //     {
    //         auto it = lower_bound(left.begin() + currLeft, left.end(), right[i], [](vector<int> a, vector<int> b) { return a[0] < b[0]; });
    //         ans[right[i][1]] = (it == left.end()) ? -1 : (*it)[1];
    //         currLeft = it - left.begin();
    //     }

    //     return ans;
    // }
};
// @lc code=end
