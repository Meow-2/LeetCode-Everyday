/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */
#include <queue>
// @lc code=start
class Solution
{
public:
    // unordered_map<int, int> heap;
    // void                    insert();
    // void                    shiftDown() {}
    int findKthLargest(vector<int>& nums, int k)
    {
        std::priority_queue<int> q(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; i++)
            q.pop();
        return q.top();
    }
};
// @lc code=end
