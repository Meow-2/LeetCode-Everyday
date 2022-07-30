/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 */
#include <climits>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
template<class T>
ostream& operator<<(ostream& x, vector<T> const& v)
{
    x << '[';
    for (auto i : v)
        x << i << ' ';
    x << "]\n";
    return x;
}
class Solution
{
public:
    // 超时
    // int  res{INT_MIN};
    // void backtrack(vector<int>& canChoose, int curCoins)
    // {
    //     // cout << canChoose << curCoins << '\n';
    //     if (!canChoose.size()) {
    //         res = max(res, curCoins);
    //         return;
    //     }
    //     for (int i = 0; i < canChoose.size(); i++) {
    //         int temp  = curCoins;
    //         int left  = i - 1 >= 0 ? canChoose[i - 1] : 1;
    //         int right = i + 1 < canChoose.size() ? canChoose[i + 1] : 1;
    //         int mid   = canChoose[i];
    //         curCoins += left * canChoose[i] * right;
    //         canChoose.erase(canChoose.begin() + i);
    //         backtrack(canChoose, curCoins);
    //         canChoose.insert(canChoose.begin() + i, mid);
    //         curCoins = temp;
    //     }
    //     return;
    // }
    int maxCoins(vector<int>& nums)
    {
        // 插入哨兵
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        // dp[i][j]表示区间可以获得的最大值, (i,j)是开区间, 所以只有 i + 1 < j 时才有值
        int    n = nums.size();
        vector dp(n, vector<int>(n, 0));
        for (int L = 1; L < n - 1; L++) {
            for (int i = 0; i < n; i++) {
                int j = i + L + 1;
                if (j < n) {
                    dp[i][j] = 0;
                    for (int k = i + 1; k < j; k++) {
                        dp[i][j] = max(dp[i][k] + nums[j] * nums[k] * nums[i] + dp[k][j], dp[i][j]);
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};
// @lc code=end