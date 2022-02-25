/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

#include <iterator>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
    {
        int                     result = 0;
        unordered_map<int, int> map12;
        unordered_map<int, int> map34;
        for (auto& i : nums1)
            for (auto& j : nums2)
                map12[i + j]++;
        for (auto& i : nums3) {
            for (auto& j : nums4) {
                auto it = map12.find(0 - i - j);
                if (map12.find(0 - i - j) != map12.end())
                    result += it->second;
            }
        }
        return result;
    }
};
// @lc code=end
