// @before-stub-for-debug-begin
#include <vector>
#include <string>
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
        int h = 1;
        while (h < numsSize / 3)
        {
            h = 3 * h + 1;
        }
        while (h >= 1)
        {
            for (int i = h; i < numsSize; i++)
            {
                int j = 0;
                int numI = nums[i];
                for (j = i; j - h >= 0 && nums[j - h] > numI; j = j - h)
                    nums[j] = nums[j - h];
                nums[j] = numI;
            }
            h = h / 3;
        }
        int maxList = 0;
        int maxListNow = 0;
        int i = 0;
        while (i < numsSize)
        {
            int numI = nums[i];
            int same0 = 0;
            int same1 = 0;
            int j, k = 0;
            for (j = i + 1; j < numsSize && nums[j] == numI; j++)
                same0++;
            for (k = j; k < numsSize && nums[k] - 1 == numI; k++)
                same1++;
            if (same1 > 0)
            {
                maxListNow = same1 + same0 + 1;
                if (maxListNow > maxList)
                    maxList = maxListNow;
            }
            i = j;
        }
        return maxList;
    }
};
// @lc code=end
