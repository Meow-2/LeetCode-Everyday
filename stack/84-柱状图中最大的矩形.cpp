/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */
#include <algorithm>
#include <climits>
#include <memory>
#include <stack>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    // 二维dp超时, dp[i][j] 是heights[i]到heights[j]间覆盖的矩形的面积
    // int largestRectangleArea(vector<int>& heights)
    // {
    //     int                 n = heights.size();
    //     vector<vector<int>> dp(n, vector<int>(n, 0));
    //     int                 maxS = INT_MIN;
    //     for (int i = 0; i < n; i++) {
    //         dp[i][i] = heights[i];
    //         maxS     = max(maxS, dp[i][i]);
    //     }
    //     for (int l = 2; l <= n; l++) {
    //         for (int i = 0; i < n; i++) {
    //             int j = i + l - 1;
    //             if (j < n) {
    //                 int h = dp[i][j - 1] / (j - i);
    //                 if (heights[j] >= h)
    //                     dp[i][j] = h * l;
    //                 else
    //                     dp[i][j] = heights[j] * l;
    //                 maxS = max(maxS, dp[i][j]);
    //             }
    //         }
    //     }
    //     return maxS;
    // }
    // 关键是找到每一个高度左边第一个低于该高度的下标和右边第一个低于该高度的下标
    int largestRectangleArea(vector<int>& heights)
    {
        int n = heights.size();
        // 保存小于heights[i]的左边第一个数的下标
        vector<int> left_low(n, -1);
        vector<int> right_low(n, -1);
        // 栈顶是与当前下标最接近的,小于当前值的下标
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            left_low[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        st = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            right_low[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        int maxS = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxS = max(maxS, heights[i] * (right_low[i] - left_low[i] - 1));
        }
        return maxS;
    }
};
// @lc code=end