/*
 * @lc app=leetcode id=497 lang=cpp
 *
 * [497] Random Point in Non-overlapping Rectangles
 */

// @lc code=start
class Solution {
public:
    vector<int> v;
    vector<vector<int>> rects;
    
    int area(const vector<int>& r) {
        return (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
    }
    
    Solution(vector<vector<int>> rect) {
        rects = rect;
        for (auto& r : rects) {
            v.push_back(area(r) + (v.empty() ? 0 : v.back())); // area at back = sum of all before
        }
    }
    
    vector<int> pick() {
        int rnd = rand() % v.back(); // v.back() = sum of area
        auto it = upper_bound(v.begin(), v.end(), rnd);
        int idx = it - v.begin(); // get the rectangle
        
        // pick a random point in rect[idx]
        auto r = rects[idx];
        return {
            rand() % (r[2] - r[0] + 1) + r[0],
            rand() % (r[3] - r[1] + 1) + r[1]
        };
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
// @lc code=end

