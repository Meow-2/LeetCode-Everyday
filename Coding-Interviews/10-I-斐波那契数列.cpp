#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    // unordered_map<int, int> mem;
    // int                     fib(int n)
    // {
    //     if (mem.count(n))
    //         return mem[n];
    //     if (n == 0)
    //         return 0;
    //     if (n == 1)
    //         return 1;
    //     auto ans = ( fib(n - 1) + fib(n - 2) )%1000000007;
    //     mem[n]   = ans;
    //     return ans;
    // }
    int fib(int n)
    {
        if (n < 2)
            return n;
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
            dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
        return dp[n];
    }
};
