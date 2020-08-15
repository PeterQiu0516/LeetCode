/*
 * @lc app=leetcode id=546 lang=cpp
 *
 * [546] Remove Boxes
 */

// @lc code=start
class Solution {
private:
    vector<vector<vector<int>>> dp;
public:
    int dps(vector<int>& boxes,int i, int j, int k){
        // i: left bound for current interval
        // j: right bound for current interval
        // k: number of blocks that has the same color as the right bound j
        if(i > j){
            return 0;
        }
        // already calculated
        if(dp[i][j][k] != 0){
            return dp[i][j][k];
        }
        // set those with the same color into the range of k and move j
        while (i < j && boxes[j] == boxes[j - 1]) {
            j--;
            k++;
        }
        
        // cut down from j
        dp[i][j][k] = dps(boxes, i, j - 1, 0) + (k + 1) * (k + 1);

        // split the interval, choose p which has the same color as j
        for (int p = i; p < j; p++) {
            if (boxes[p] == boxes[j]) {
                // k+1: the jth block + k afterwards
                dp[i][j][k] = max(dp[i][j][k], dps(boxes, p + 1, j - 1, 0) + dps(boxes, i, p, k + 1));
            }
        }
        return dp[i][j][k];
    }

    int removeBoxes(vector<int>& boxes) {
        int size = static_cast<int>(boxes.size());
        // initialize
        dp = vector<vector<vector<int>>>(size,vector<vector<int>>(size,vector<int>(size,0)));
        // answer would be: considering the whole interval
        return dps(boxes, 0, boxes.size() - 1, 0);
    }
};
// @lc code=end

