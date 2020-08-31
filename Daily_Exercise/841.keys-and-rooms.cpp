/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 */

// @lc code=start
class Solution
{
    vector<int> visit;

public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        visit = vector<int>(rooms.size(), 0);
        dfs(rooms,0);
        for (int i = 0; i < visit.size(); i++)
        {
            if(!visit[i]) return false;
        }
        
        return true;
    }

    void dfs(vector<vector<int>> &rooms, int pos)
    {
        if (visit[pos] == 1)
            return;
        visit[pos] = 1;
        for (int i = 0; i < rooms[pos].size(); i++)
        {
            dfs(rooms,rooms[pos][i]);
        }
    }
};
// @lc code=end
