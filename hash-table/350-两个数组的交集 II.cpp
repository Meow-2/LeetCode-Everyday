/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_map<int, int> nums1Count;
        vector<int>             result;
        for (auto num : nums1)
            nums1Count[num]++;
        for (auto num : nums2) {
            if (nums1Count[num] > 0) {
                result.push_back(num);
                nums1Count[num]--;
            }
        }
        return result;
    }
};
// @lc code=end
