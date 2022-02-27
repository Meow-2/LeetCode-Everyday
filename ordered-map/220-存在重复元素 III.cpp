/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */

#include <cstdio>
#include <iterator>
#include <set>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
    {
        if (nums.size() < 2)
            return false;
        set<long> windowNum;
        int       left = 0, right = 0;   //[left,right)
        while (right < nums.size()) {
            auto it = windowNum.lower_bound((long)nums[right] - t);
            // printf("%d %d\n", nums[right], *it);
            if (it != windowNum.end() && *it <= (long)nums[right] + t)
                return true;
            windowNum.insert((long)nums[right]);
            right++;
            while (right - 1 - left == k) {
                windowNum.erase((long)nums[left]);
                left++;
            }
        }
        return false;
    }
};
// @lc code=end