/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool containsDuplicate(vector<int>& nums)
    {
        unordered_map<int, int> numIndex;
        for (auto& i : nums) {
            if (numIndex.find(i) != numIndex.end()) {
                return true;
            }
            numIndex[i] = i;
        }
        return false;
    }
    // bool containsDuplicate(vector<int>& nums)
    // {
    //     unordered_set numsSet(nums.begin(), nums.end());
    //     return numsSet.size() == nums.size() ? false : true;
    // }
};
// @lc code=end
