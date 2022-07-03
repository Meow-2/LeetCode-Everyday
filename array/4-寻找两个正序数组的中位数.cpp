/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution
{
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        auto   nums1_len = static_cast<double>(nums1.size());
        auto   nums2_len = static_cast<double>(nums2.size());
        int    i = 0, j = 0;
        auto   fl   = floor((nums1_len + nums2_len) / 2);
        auto   ce   = ceil((nums1_len + nums2_len) / 2);
        auto   mid0 = fl == ce ? fl - 1 : fl;
        auto   mid1 = fl == ce ? ce : ce - 1;
        double res0 = 0, res1 = 0;
        for (int k = 0; k <= mid1; k++) {
            double smaller = 0;
            if (i < nums1.size() && j < nums2.size()) {
                if (nums1[i] < nums2[j])
                    smaller = nums1[i++];
                else
                    smaller = nums2[j++];
            }
            else if (i < nums1.size())
                smaller = nums1[i++];
            else if (j < nums2.size())
                smaller = nums2[j++];
            if (k == mid0)
                res0 = smaller;
            if (k == mid1)
                res1 = smaller;
        }
        return (res0 + res1) / 2;
    }
};
// @lc code=end
