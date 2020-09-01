/*
 * @lc app=leetcode id=952 lang=cpp
 *
 * [952] Largest Component Size by Common Factor
 */

// @lc code=start
// class Solution {
// public:
//     int largestComponentSize(vector<int>& A) {
//         int n = 0, mx = 0, res = 0;
//         unordered_map<int, int> m;
//         for (int num : A) mx = max(mx, num);
//         vector<int> root(mx + 1);
//         for (int i = 1; i <= mx; ++i) root[i] = i;
//         for (int num : A) {
//             for (int d = sqrt(num); d >= 2; --d) {
//                 if (num % d == 0) {
//                     root[find(root, num)] = root[find(root, d)];
//                     root[find(root, num)] = root[find(root, num / d)];
//                 }
//             }
//         }
//         for (int num : A) {
//             res = max(res, ++m[find(root, num)]);
//         }
//         return res;
//     }
//     int find(vector<int>& root, int x) {
//         return root[x] == x ? x : (root[x] = find(root, root[x]));
//     }
// };

// W: the largest number
// Time Complexity: O(n*sqrt(W))
// Space Complexity: O(W)

class UnionFindSet
{
public:
    UnionFindSet(int n) : parent(n)
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    void Union(int x, int y)
    {
        parent[Find(x)] = Find(y);
    }

    int Find(int x)
    {
        // return parent[x] == x ? x : Find(parent[x]);
        // for this problem, we can just set all parent back to the same ancestor, 
        return parent[x] == x ? x : parent[x]=Find(parent[x]);
    }

private:
    vector<int> parent;
};

class Solution
{
public:
    int largestComponentSize(vector<int> &A)
    {
        int n = *max_element(A.begin(), A.end());
        UnionFindSet ufs(n + 1);
        for (int &a : A)
        {
            for (int k = 2; k <= sqrt(a); k++)
            {
                if (a % k == 0)
                {
                    ufs.Union(a, k); // let a to be union with its factors
                    ufs.Union(a, a / k);
                }
            }
        }

        unordered_map<int, int> mp;
        int ans = 1;
        for (int &a : A)
        {
            ans = max(ans, ++mp[ufs.Find(a)]); // all numbers that share a common divisor will have the same Find()(ancestor) for ufs
        }
        return ans;
    }
};
// @lc code=end
