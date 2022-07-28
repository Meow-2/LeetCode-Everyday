/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */
#include <algorithm>
#include <ctime>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    // 二分查找, 重复的数target的范围在[1,n]之间
    // int findDuplicate(vector<int>& nums)
    // {
    //     int left  = 1;
    //     int right = nums.size() - 1;
    //     int res   = -1;
    //     while (left <= right) {
    //         int mid   = left + ((right - left) >> 1);
    //         int count = 0;
    //         for_each(nums.begin(), nums.end(), [&](int a) {
    //             if (a <= mid)
    //                 count += 1;
    //         });
    //         if (count <= mid)
    //             left = mid + 1;
    //         else {
    //             right = mid - 1;
    //             res   = mid;
    //         }
    //     }
    //     return res;
    // }

    // 位运算
    // int findDuplicate(vector<int>& nums)
    // {
    //     int res = 0;
    //     for (int i = 0; i < 32; i++) {
    //         int x = 0;
    //         int y = 0;
    //         for_each(nums.begin(), nums.end(), [&](int a) { x += a & (1 << i) ? 1 : 0; });
    //         for (int j = 1; j < nums.size(); j++)
    //             y += j & (1 << i) ? 1 : 0;
    //         if (x > y)
    //             res |= (1 << i);
    //     }
    //     return res;
    // }

    // 双指针, 抽象成环形链表
    int findDuplicate(vector<int>& nums)
    {
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
// @lc code=end