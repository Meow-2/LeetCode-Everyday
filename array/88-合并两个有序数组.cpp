/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int         i = 0;
        int         j = 0;
        vector<int> sorted;
        while (i < m || j < n) {
            if (i == m) {
                sorted.push_back(nums2[j]);
                j++;
            }
            else if (j == n) {
                sorted.push_back(nums1[i]);
                i++;
            }
            else if (nums1[i] <= nums2[j]) {
                sorted.push_back(nums1[i]);
                i++;
            }
            else {
                sorted.push_back(nums2[j]);
                j++;
            }
        }
        nums1 = sorted;
    }
};
// @lc code=end
int main()
{
    vector<int> nums1 = {7, 6, 5, 4};
    vector<int> nums2 = { 6, 5, 4, 4, 3, 2, 1 }
}