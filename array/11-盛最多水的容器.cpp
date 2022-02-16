/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
#include <iterator>
#include <vector>
using namespace std;
class Solution
{
public:
    // 暴力
    // int maxArea(vector<int>& height)
    // {
    //     int n0 = 0, n1 = 1, maxWater = min(height[n0], height[n1]) * (n1 - n0);
    //     for (int i = 0; i < height.size() - 1; i++) {
    //         if (maxWater < height[i] * (height.size() - i - 1)) {
    //             for (int j = 1; j < height.size(); j++) {
    //                 int water = min(height[i], height[j]) * (j - i);
    //                 if (water > maxWater) {
    //                     maxWater = water;
    //                     n0       = i;
    //                     n1       = j;
    //                 }
    //             }
    //         }
    //     }
    //     return maxWater;
    // }

    // 对撞指针
    int maxArea(vector<int>& height)
    {
        int left = 0, right = height.size() - 1;
        int maxWater = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                maxWater = max(maxWater, height[left] * (right - left));
                left++;
            }
            else if (height[left] >= height[right]) {
                maxWater = max(maxWater, height[right] * (right - left));
                right--;
            }
        }
        return maxWater;
    }
};
// @lc code=end
