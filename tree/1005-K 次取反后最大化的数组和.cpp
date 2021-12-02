/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        int a[201] = {0};
        int sum = 0;
        for (auto i : nums)
        {
            a[i + 100]++;
            sum += i;
        }
        int minNum = 101;
        for (int i = 0; i < 100; i++)
        {
            if (a[i] != 0)
            {
                sum += 2 * (100 - i) * min(k, a[i]);
                k -= min(k, a[i]);
                if (k == 0)
                    return sum;
                minNum = 100 - i;
            }
        }
        if (k % 2 == 0)
            return sum;
        else
        {
            int minNum2;
            for (minNum2 = 100; minNum2 < 201 && a[minNum2] == 0; minNum2++)
            {
            }
            return sum - 2 * min(minNum, minNum2 - 100);
        }
    }
};
// @lc code=end
