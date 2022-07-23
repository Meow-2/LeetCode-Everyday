/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */
#include <array>
#include <cmath>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    // 位运算, 对 res 的每一位分别求解, 数组里的所有数按位加起来, 统计每一个位上 1 的数量, 如果 1
    // 的数量大于一半, 说明要求的数那一位上是 1 , 否则是0
    // int majorityElement(vector<int>& nums)
    // {
    //     int            n = nums.size();
    //     array<int, 32> bit;
    //     bit.fill(0);
    //     for (auto i : nums) {
    //         for (int j = 0; j < 32; j++) {
    //             // 取位一般用&
    //             bit[j] += ((1 << j) & i) ? 1 : 0;
    //         }
    //     }
    //     int res = 0;
    //     for (int i = 0; i < 32; i++) {
    //         if (bit[i] > floor(n / 2)) {
    //             res = res | (1 << i);
    //         }
    //     }
    //     return res;
    // }

    // 位运算, 优化了空间复杂度, 因为每个位之间互相独立不影响,
    // 所以只需用一个变量来记录每个位上 1 的数量即可 int majorityElement(vector<int>& nums)
    // {
    //     int res = 0;
    //     for (int i = 0; i < 32; i++) {
    //         int sum = 0;
    //         for (auto j : nums)
    //             sum += (1 << i & j) ? 1 : 0;
    //         if (sum > floor(nums.size() / 2))
    //             res += 1 << i;
    //     }
    //     return res;
    // }

    // 摩尔投票法
    int majorityElement(vector<int>& nums)
    {
        int votes     = 0;
        int candidate = 0;
        for (auto i : nums) {
            if (!votes)
                candidate = i;
            votes = i == candidate ? votes + 1 : votes - 1;
        }
        return candidate;
    }
};
// @lc code=end
