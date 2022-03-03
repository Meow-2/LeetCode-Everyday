/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */

#include <cstdio>
#include <ios>
#include <iterator>
#include <set>
#include <tuple>
#include <unordered_map>
#include <utility>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
    {
        if (nums.size() < 2)
            return false;
        set<int> windowNum;
        int      left = 0, right = 0;   //[left,right)
        while (right < nums.size()) {
            auto it = windowNum.lower_bound(max(nums[right], INT_MIN + t) - t);
            // printf("%d %d\n", nums[right], *it);
            if (it != windowNum.end() && *it <= min(nums[right], INT_MAX - t) + t)
                return true;
            windowNum.insert(nums[right]);
            right++;
            if (right - 1 - left == k) {
                windowNum.erase(nums[left]);
                left++;
            }
        }
        return false;
    }
};
// @lc code=end
