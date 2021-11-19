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
        unsigned int N = n;
        int count = 0;
        while (N > 1)
        {
            if (N % 2 == 0)
            {
                N /= 2;
                count++;
            }
            else
            {
                int nDec = N - 1;
                if (nDec / 2 > 1 && (nDec / 2) % 2 == 1)
                {
                    N++;
                    count++;
                }
                else
                {
                    N = nDec;
                    count++;
                }
            }
        }
        return count;
    }
};
// @lc code=end
