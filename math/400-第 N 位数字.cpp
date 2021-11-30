/*
 * @lc app=leetcode.cn id=400 lang=cpp
 *
 * [400] 第 N 位数字
 */

// @lc code=start
#include <string>
using namespace std;
class Solution
{
public:
    int findNthDigit(int n)
    {
        long temp = n;
        int i = 0;
        while (temp > 0)
        {
            i++;
            temp -= i * 9 * pow(10, i - 1);
        }
        long num = pow(10, i + 1) - 1 - (-temp) / i;
        string s = to_string(num);
        return s[s.size() - 1 - (-temp) % i] - '0';
    }
};
// @lc code=end
