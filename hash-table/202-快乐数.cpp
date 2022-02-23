/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

#include <cmath>
#include <cstdio>
#include <math.h>
#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int next(int n)
    {
        int sum = 0;
        while (n > 0) {
            sum += pow(n % 10, 2);
            n /= 10;
        }
        return sum;
    }
    // bool isHappy(int n)
    // {
    //     unordered_set<int> a;
    //     a.insert(n);
    //     while (n != 1) {
    //         n = next(n);
    //         if (a.find(n) == a.end())
    //             a.insert(n);
    //         else
    //             break;
    //     }
    //     return n == 1 ? true : false;
    // }
    bool isHappy(int n)
    {
        int slow = n;
        int fast = n;
        do {
            slow = next(slow);
            fast = next(next(fast));
        } while (slow != fast);
        return slow == 1;
    }
};
// @lc code=end