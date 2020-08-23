/*
 * @lc app=leetcode id=679 lang=cpp
 *
 * [679] 24 Game
 */

// @lc code=start
class Solution
{
public:
    static constexpr int TARGET = 24;
    static constexpr double EPSILON = 1e-6; // avoid float error
    static constexpr int ADD = 0, MULTIPLY = 1, SUBTRACT = 2, DIVIDE = 3;

    bool judgePoint24(vector<int> &nums)
    {
        vector<double> list;
        for (int &num : nums)
        {
            list.emplace_back(static_cast<double>(num));
        }
        return solve(list);
    }

    bool solve(vector<double> &list)
    {
        if (list.size() == 0)
        {
            return false;
        }
        if (list.size() == 1)
        {
            return fabs(list[0] - TARGET) < EPSILON;
        }
        int size = list.size();
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (i != j) // operator has order
                {
                    vector<double> list2 = vector<double>();
                    for (int k = 0; k < size; k++) // iterate through rest 2 or 1 element
                    {
                        if (k != i && k != j)
                        {
                            list2.emplace_back(list[k]);
                        }
                    }
                    for (int k = 0; k < 4; k++) // iterate through all operations
                    {
                        if (k < 2 && i > j) // ADD and MULTIPLY do not have order, could eliminate half of the cases
                        {
                            continue;
                        }
                        switch (k)
                        {
                        case ADD:
                            list2.emplace_back(list[i] + list[j]);
                            break;
                        case MULTIPLY:
                            list2.emplace_back(list[i] * list[j]);
                            break;
                        case SUBTRACT:
                            list2.emplace_back(list[i] - list[j]);
                            break;
                        case DIVIDE:
                            if (fabs(list[j]) < EPSILON) // 0
                            {
                                continue;
                            }
                            list2.emplace_back(list[i] / list[j]);
                            break;
                        }
                        if (solve(list2)) // recursively solve for 3 or 2 elements
                        {
                            return true;
                        }
                        list2.pop_back(); // eliminate current calculated result of list[i] & list[j]
                    }
                }
            }
        }
        return false;
    }
};
// @lc code=end
