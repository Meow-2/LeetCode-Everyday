/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        unordered_map<int, int> numIndex;
        for (int i = 0; i < nums.size(); i++) {
            if (numIndex.find(nums[i]) != numIndex.end()) {
                if (i - numIndex[nums[i]] <= k)
                    return true;
            }
            numIndex[nums[i]] = i;
        }
        return false;
    }
};
// @lc code=end
