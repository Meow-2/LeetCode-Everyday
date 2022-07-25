/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
#include <queue>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        vector<int> res;
        // pair<int,int> -> <val,pos>
        priority_queue<pair<int, int>> q;
        int                            i;
        for (i = 0; i < k; i++) {
            q.push({nums[i], i});
        }
        res.push_back(q.top().first);
        while (i < nums.size()) {
            q.push({nums[i], i});
            while (q.top().second < i - k + 1)
                q.pop();
            res.push_back(q.top().first);
            i++;
        }
        return res;
    }
};
// @lc code=end
