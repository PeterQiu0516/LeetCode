/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        dfs(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }

    void dfs(vector<vector<int>> &image, int sr, int sc, int newColor, int startColor)
    {
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size())
            return;
        if (image[sr][sc] != startColor || image[sr][sc] == newColor) // already visited
            return;
        image[sr][sc] = newColor;
        dfs(image, sr - 1, sc, newColor,startColor);
        dfs(image, sr, sc - 1, newColor,startColor);
        dfs(image, sr + 1, sc, newColor,startColor);
        dfs(image, sr, sc + 1, newColor,startColor);
    }
};
// @lc code=end
