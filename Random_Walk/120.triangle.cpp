/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for (int pos =n-2; pos >=0; pos--)
            for (int j =0; j <= pos ; j++)
                triangle[pos][j] += min(triangle[pos+1][j],triangle[pos+1][j+1]);
        return triangle[0][0];
    }
};
// @lc code=end

