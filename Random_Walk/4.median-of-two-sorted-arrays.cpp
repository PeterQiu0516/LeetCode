/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();

        // Boundary case
        if (m == 0)
            return (n % 2 == 0) ? double((nums2[n / 2 - 1] + nums2[n / 2]) / 2.0) : double(nums2[(n - 1) / 2]);
        if (n == 0)
            return (m % 2 == 0) ? double((nums1[m / 2 - 1] + nums1[m / 2]) / 2.0) : double(nums1[(m - 1) / 2]);

        // General case
        int len = m;
        int l = 0, r = len - 1;
        int curr;

        for (int i = 0; i < n; i++)
        {
            // Use binary search to insert each element into nums1
            int num = nums2[i];
            while (1)
            {
                if (l == r)
                {
                    if (num < nums1[l])
                        curr = l;
                    else
                        curr = l + 1;
                    nums1.insert(nums1.begin() + curr, num);
                    break;
                }
                else if (num > nums1[r])
                {
                    l = r;
                    r = len - 1;
                }
                else if (num < nums1[l])
                {
                    r = l;
                    l = 0;
                }
                else if (num <= nums1[r])
                    r = floor((double)(l + r) / 2.0);
                else if (num > nums1[l])
                    l = ceil((double)(l + r) / 2.0);
            }
            len++;
            l = curr;
            r = len - 1;
        }

        if ((m + n) % 2 == 0)
            return double(nums1[(m + n) / 2 - 1] + nums1[(m + n) / 2]) / 2.0; // ATTENTION, 2.0 here
        return double(nums1[(m + n - 1) / 2]);
    }
};
// @lc code=end
