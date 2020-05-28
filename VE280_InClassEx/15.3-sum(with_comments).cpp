/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        clock_t startTime, endTime;

        // // // input, for testing
        // freopen("1.txt", "r", stdin);
        // vector<int> nums;
        // int n;
        // cin >> n;
        // for (int i = 0; i < n; i++)
        // {
        //     int tmp;
        //     cin >> tmp;
        //     nums.push_back(tmp);
        // }
        // n = nums.size();
        int n = nums.size();

        vector<vector<int>> ans;

        unordered_map<int, int> counts; // Optimization for repetive cases
        unordered_map<int, int> one_sum;
        // // for a single int, we dont have to use unordered_map<int, vector<int>>, unordered_map<int, int> is enough

        // unordered_map<int, vector<int>> one_sum;
        // // Warning: This is a construction & search complexity trade-off. Search complexity for unordered_map is O(n) (hashtable), but construction takes a lot of time!!!
        // // So we should not implement an unordered_map two_sum; with search Complexity O(n) but takes a lot of constrution time to construct two_sum (O(n^2) * Single Construction)
        // // use an unordered_map<int, int> instead and use a O(n^2) loop to search.
        // unordered_map<int, vector<int>> two_sum;

        // startTime = clock();
        // cout << "start time is " << (double)(startTime) / CLOCKS_PER_SEC << "s" << endl;

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                counts[-(nums[i] + nums[j])] = 0;
            }
        }

        // // generate the map for one_sum
        for (int i = 0; i < n; i++)
        {
            one_sum[nums[i]] = i;
            if (counts.count(nums[i]) == 0)
            {
                counts[nums[i]] = 1;
            }
            else
            {
                counts[nums[i]]++;
            }
            //one_sum[nums[i]].push_back(i);
        }

        // // // generate the map for two_sum
        // for (int i = 0; i < n - 1; i++)
        // {
        //     for (int j = i + 1; j < n; j++)
        //     {
        //         two_sum[nums[i] + nums[j]].push_back(i);
        //         two_sum[nums[i] + nums[j]].push_back(j);
        //     }
        // }

        // endTime = clock();
        // cout << "Map generation time is " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
        // startTime = clock();

        // // debug for unordered_map<int, vector<int>>
        // cout << two_sum[11].size() << endl;
        // cout << two_sum[11][0]<< endl;
        // cout << two_sum[11][1]<< endl;
        // cout << two_sum.find(3)->second[0] << endl;
        // cout << two_sum.find(3)->second[1] << endl;
        // cout << two_sum.find(1)->second.size() << endl;
        // for (int i = 0; i < two_sum.find(1)->second.size() / 2; i++)
        // {
        //     cout << "sum 1 index:" << two_sum.find(1)->second[2 * i] << " " << two_sum.find(1)->second[2 * i + 1] << endl;
        // }
        // cout << "index end" << endl;

        // // debug for vector
        // vector<int> tmp={5,4,1};
        // sort(tmp.begin(),tmp.end());
        // for (int i =0; i < tmp.size(); i++)
        // {
        //     cout << tmp[i] << " ";
        // }
        // cout << endl;

        // // deal with the output (no duplicate, but in order)
        set<vector<int>> all_ans;
        //vector<vector<int>> all_ans;

        // // ordered set will rank the solution by default
        //set<vector<int>> all_ans;

        // // single should not be set since [-1 0 1 2 -1 -4] [-1 -1 2]
        //set<set<int>> all_ans;

        // // unordered_set is rubbish bin (in rubbish order)
        //unordered_set<vector<int>> all_ans;

        // // not index, different combination of index can generate the same 3 numbers e.g. [-1 0 1 2 -1 -4] index[0 1 2] = index[1 2 4]
        //set<set<int>> all_ans_index;

        // search for one_sum map
        // simplify the case
        if (counts[0] >= 3)
            ans.push_back({0, 0, 0});

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (counts[-(nums[i] + nums[j])] == 0)
                {
                    continue;
                }
                if (nums[i] == 0 && nums[j] == 0)
                {
                    continue;
                }
                // else
                // {
                //     counts[-(nums[i] + nums[j])]--;
                // }
                // int x = nums[i], y = nums[j], z = -x - y;
                // int k=one_sum[z];
                // if (i != k && j != k)
                // {
                //     vector<int> single_ans = {x,y,z};
                //     sort(single_ans.begin(), single_ans.end());
                //     all_ans.insert(single_ans);
                // }
                if (i != one_sum[-(nums[i] + nums[j])] && j != one_sum[-(nums[i] + nums[j])])
                {
                    vector<int> single_ans = {nums[i], nums[j], -(nums[i] + nums[j])};
                    sort(single_ans.begin(), single_ans.end());
                    all_ans.insert(single_ans);
                }
            }
        }

        // // search for two_sum map
        // for (int i = 0; i < n; i++)
        // {
        //     unordered_map<int, vector<int>>::iterator tmp;
        //     // tmp = two_sum.end();
        //     tmp = two_sum.find(-nums[i]);
        //     if (tmp != two_sum.end())
        //     {
        //         for (int j = 0; j < tmp->second.size() / 2; j++)
        //         {
        //             if (i != two_sum[-nums[i]][2 * j] && i != two_sum[-nums[i]][2 * j + 1])
        //             {
        //                 // // debug of unordered map
        //                 // cout << "---Got it!---"  << endl;
        //                 int index1 = two_sum[-nums[i]][2 * j];
        //                 int index2 = two_sum[-nums[i]][2 * j + 1];
        //                 // cout << i << " " << index1 << " " << index2 << endl;
        //                 // cout << nums[i] << " " << nums[index1] <<" "<< nums[index2] << endl;
        //                 // cout << "---Printed---" << endl;

        //                 // // single ans

        //                 // // not set of set, since [-1,-1,2] for [-1 0 1 2 -1 -4]
        //                 //set<int> single_ans = {nums[i], nums[index1], nums[index2]};
        //                 //all_ans.insert(single_ans);

        //                 // // not set of vector, since the vector will be ordered by set
        //                 //ans.push_back({nums[ans_index[0]], nums[ans_index[1]], nums[ans_index[2]]});

        //                 // // not index for single ans, different combination of index can generate the same 3 numbers e.g. [-1 0 1 2 -1 -4] index[0 1 2] = index[1 2 4]
        //                 //set<int> ans_index = {i, index1, index2};
        //                 //vector<int> ans_index = {i, index1, index2};
        //                 //sort(ans_index.begin(), ans_index.end());

        //                 vector<int> single_ans = {nums[i], nums[index1], nums[index2]};
        //                 sort(single_ans.begin(), single_ans.end());

        //                 // // no duplicate
        //                 all_ans.insert(single_ans);
        //                 // if (find(all_ans.begin(), all_ans.end(), single_ans) == all_ans.end())
        //                 //     all_ans.push_back(single_ans);
        //             }
        //         }
        //     }
        // }

        // endTime = clock();
        // cout << "search time is " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
        // startTime = clock();

        for (set<vector<int>>::iterator itx = all_ans.begin(); itx != all_ans.end(); itx++)
        {
            vector<int> single_ans;
            // for set<vector<int>> we can not use (*(itx)) to access
            // for(vector<int>::iterator ity= (*(itx)).begin(); ity != (*(itx)).end();ity++)
            //     single_ans.push_back(*ity);
            ans.push_back((*itx));
        }

        // // output, for testing
        // for (int i = 0; i < ans.size(); i++)
        // {
        //     for (int j = 0; j <= 2; j++)
        //     {
        //         cout << ans[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        // endTime = clock();
        // cout << "The total run time is " << (double)(endTime) / CLOCKS_PER_SEC << "s" << endl;
        return ans;
    }
};
// @lc code=end
