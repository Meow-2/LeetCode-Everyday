/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int trap(vector<int>& height)
    {
        vector<int> left_max(height.size(), -1);
        vector<int> right_max(height.size(), -1);
        int         sum = 0;
        for (int i = 1; i < height.size() - 1; i++) {
            left_max[i] = max(left_max[i - 1], height[i - 1]);
        }
        // cout << "left_max:{ ";
        // for (auto const& element : left_max) {
        //     cout << element << ' ';
        // }
        // cout << '}' << '\n';
        for (int i = height.size() - 2; i >= 1; i--) {
            right_max[i] = max(right_max[i + 1], height[i + 1]);
        }
        // cout << "right_max:{ ";
        // for (auto const& element : right_max) {
        //     cout << element << ' ';
        // }
        // cout << '}' << '\n';
        for (int i = 1; i < height.size() - 1; i++) {
            // cout << "left_max[" << i << "]" << left_max[i] << "right_max[" << i << "]"
            //      << right_max[i] << '\n';
            int left_right_low = min(left_max[i], right_max[i]);
            sum += height[i] > left_right_low ? 0 : (left_right_low - height[i]);
        }
        return sum;
    }
};
// @lc code=end
