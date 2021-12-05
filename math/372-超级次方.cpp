// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <cmath>
#include "commoncppproblem372.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=372 lang=cpp
 *
 * [372] 超级次方
 */

// @lc code=start
class Solution
{
public:
    int superPow(int a, vector<int> &b)
    {
        a = a % 1337;
        if (a == 1)
            return 1;
        else if (a == 0)
            return 0;
        else
        {
            int x = 1; // pow(a,x)
            int numB = 12;
            int res = 1;
            do
            {
                for (x = 1; pow(a, x) < 1337; x++)
                    ;
                numB = 12;
                if (b.size() == 1)
                    numB = b[0];
                else if (b.size() == 2)
                    numB = b[0] * 10 + b[1];
                if (x > numB)
                    return (res * (int)pow(a, numB)) % 1337;
                else
                {
                    int remainder = 0;
                    for (int i = 0; i < b.size(); i++)
                    {
                        int temp = b[i] + remainder * 10;
                        b[i] = temp / x;
                        remainder = temp % x;
                    }
                    for (auto it = b.begin(); it != b.end();)
                    {
                        if (*it != 0)
                            break;
                        else
                        {
                            it = b.erase(it);
                        }
                    }

                    res = (res * (int)pow(a, remainder)) % 1337;
                    a = (int)pow(a, x) % 1337;
                }
            } while (true);
        }
    }
};
// @lc code=end
