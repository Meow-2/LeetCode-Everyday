// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=594 lang=cpp
 *
 * [594] 最长和谐子序列
 */
// @lc code=start
class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        int numsSize = nums.size();
        //标准库的排序函数果然比我自己写的哈希排序要快了N倍,orz
        // int h = 1;
        // while (h < numsSize / 3)
        // {
        //     h = 3 * h + 1;
        // }
        // while (h >= 1)
        // {
        //     for (int i = h; i < numsSize; i++)
        //     {
        //         int j = 0;
        //         int numI = nums[i];
        //         for (j = i; j - h >= 0 && nums[j - h] > numI; j = j - h)
        //             nums[j] = nums[j - h];
        //         nums[j] = numI;
        //     }
        //     h = h / 3;
        // }
        sort(nums.begin(), nums.end());
        int maxList = 0;
        int maxListNow = 0;
        int i = 0;
        int sameLast = 0;
        while (i < numsSize)
        {
            int numI = nums[i];
            int sameThis = 1;
            int j = 0;
            for (j = i + 1; j < numsSize && nums[j] == numI; j++)
                sameThis++;
            if (i - 1 >= 0 && numI - 1 == nums[i - 1])
            {
                maxListNow = sameLast + sameThis;
                if (maxListNow > maxList)
                    maxList = maxListNow;
            }
            i = j;
            sameLast = sameThis;
        }
        return maxList;
    }
};
// @lc code=end
