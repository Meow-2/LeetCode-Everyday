/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 */
#include <stack>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    // int findUnsortedSubarray(vector<int>& nums)
    // {
    //     // 单调递增栈, pair->nums[i],i
    //     stack<pair<int, int>> s;
    //     // [0.left)为排序好的
    //     // (right,nums.size() - 1]为排序好的
    //     int left  = nums.size() - 1;
    //     int right = 0;
    //     for (int i = 0; i < nums.size(); i++) {
    //         while (!s.empty() && s.top().first > nums[i]) {
    //             left = min(s.top().second, left);
    //             s.pop();
    //         }
    //         s.push({nums[i], i});
    //     }
    //     s = stack<pair<int, int>>();
    //     for (int i = nums.size() - 1; i >= 0; i--) {
    //         while (!s.empty() && s.top().first < nums[i]) {
    //             right = max(s.top().second, right);
    //             s.pop();
    //         }
    //         s.push({nums[i], i});
    //     }
    //     return left >= right ? 0 : right - left + 1;
    // }

    // 单调栈其实只需要记录下元素的下标就可以了
    int findUnsortedSubarray(vector<int>& nums)
    {
        // 单调递增栈, pair->nums[i],i
        stack<int> s;
        // [0.left)为排序好的
        // (right,nums.size() - 1]为排序好的
        int left  = nums.size() - 1;
        int right = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (!s.empty() && nums[s.top()] > nums[i]) {
                left = min(s.top(), left);
                s.pop();
            }
            s.push(i);
        }
        s = stack<int>();
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!s.empty() && nums[s.top()] < nums[i]) {
                right = max(s.top(), right);
                s.pop();
            }
            s.push(i);
        }
        return left >= right ? 0 : right - left + 1;
    }
};
// @lc code=end
