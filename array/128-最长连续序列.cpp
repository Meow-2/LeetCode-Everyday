/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */
#include <set>
#include <unordered_map>
// #include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    // int longestConsecutive(vector<int>& nums)
    // {
    //     //数字对应的连续序列长度
    //     unordered_map<int, int> m;
    //     set<int>                s;
    //     int                     res = 0;
    //     for (auto& i : nums) {
    //         s.insert(i);
    //     }
    //     // 连续序列中最大数保存着连续序列的长度, 其余的数仅表示存不存在
    //     for (auto& i : s) {
    //         auto temp = i;
    //         while (m.count(temp + 1))
    //             ++temp;
    //         m[i] = 1;
    //         if (m.count(i + 1)) {
    //             if (m.count(i - 1))
    //                 m[temp] += m[i - 1] + 1;
    //             else
    //                 m[temp] += 1;
    //         }
    //         else if (m.count(i - 1))
    //             m[temp] = m[i - 1] + 1;
    //         res = max(res, m[temp]);
    //     }
    //     return res;
    // }
    // int longestConsecutive(vector<int>& nums)
    // {
    //     //数字对应的连续序列长度, 其实只需要维护序列的端点就好了
    //     unordered_map<int, int> m;
    //     // unordered_set<int>      s;
    //     int res = 0;
    //     for (auto& i : nums) {
    //         if (m.count(i))
    //             continue;
    //         m[i]       = 1;
    //         int length = 1;
    //         if (m.count(i - 1) && m.count(i + 1)) {
    //             length          = 1 + m[i - 1] + m[i + 1];
    //             m[i - m[i - 1]] = length;
    //             m[i + m[i + 1]] = length;
    //         }
    //         else if (m.count(i - 1)) {
    //             length          = m[i - 1] + 1;
    //             m[i]            = length;
    //             m[i - m[i - 1]] = length;
    //         }
    //         else if (m.count(i + 1)) {
    //             length          = m[i + 1] + 1;
    //             m[i]            = length;
    //             m[i + m[i + 1]] = length;
    //         }
    //         res = max(res, length);
    //     }
    //     return res;
    // }
    //超级简化版
    int longestConsecutive(vector<int>& nums)
    {
        //数字对应的连续序列长度, 其实只需要维护序列的端点就好了
        unordered_map<int, int> m;
        // unordered_set<int>      s;
        int res = 0;
        for (auto& i : nums) {
            if (m.count(i) && m[i] != 0)
                continue;
            m[i]            = 1;
            int length      = 1 + m[i - 1] + m[i + 1];
            m[i - m[i - 1]] = length;
            m[i + m[i + 1]] = length;
            res             = max(res, length);
        }
        return res;
    }
};
// @lc code=end
