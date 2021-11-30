// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem400.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=400 lang=cpp
 *
 * [400] 第 N 位数字
 */

// @lc code=start
#include <string>
#include <cmath>
using namespace std;
class Solution
{
public:
    int findNthDigit(int n)
    {
        int temp = n;
        int i = 1;
        //使用差值比较，防止溢出
        while (temp > i * 9 * pow(10, i - 1))
        {
            temp -= i * 9 * pow(10, i - 1);
            i++;
        }
        int num = pow(10, i - 1) + (temp % i == 0 ? (temp / i - 1) : temp / i);
        string s = to_string(num);
        return s[temp % i == 0 ? s.size() - 1 : temp % i - 1] - '0';
    }
};
// @lc code=end
