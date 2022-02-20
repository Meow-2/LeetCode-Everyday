/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
#include <set>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        set<int> num1Set(nums1.begin(), nums1.end());
        set<int> result;
        for (auto i : nums2) {
            if (num1Set.find(i) != num1Set.end()) {
                result.insert(i);
            }
        }
        return vector<int>(result.begin(), result.end());
    }
};
// @lc code=end
