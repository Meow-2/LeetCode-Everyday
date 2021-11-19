// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=397 lang=cpp
 *
 * [397] 整数替换
 */

// @lc code=start
class Solution
{
public:
    int integerReplacement(int n)
    {
        unsigned int n0 = n;
        int count = 0;
        while (n0 > 1)
        {
            if (n0 % 2 == 0)
            {
                n0 /= 2;
                count++;
            }
            else
            {
                int nDec = n0 - 1;
                if (nDec / 2 > 1 && (nDec / 2) % 2 == 1)
                {
                    n0++;
                    count++;
                }
                else
                {
                    n0 = nDec;
                    count++;
                }
            }
        }
        return count;
    }
};
// @lc code=end
