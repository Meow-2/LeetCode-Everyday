/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    // int coinChange(vector<int>& coins, int amount)
    // {
    //     if (!amount)
    //         return 0;
    //     std::sort(coins.rbegin(), coins.rend());
    //     unordered_map<long long, int> m;
    //     queue<pair<long long, int>>   q;
    //     q.push({0, 0});
    //     // std::cout << '\n';
    //     while (!q.empty()) {
    //         for (int i = 0; i < q.size(); i++) {
    //             auto f = q.front();
    //             q.pop();
    //             for (auto i : coins) {
    //                 long long temp  = f.first + i;
    //                 int       layer = f.second + 1;
    //                 if (m.count(temp) && m[temp] <= layer)
    //                     continue;
    //                 if (temp == amount)
    //                     return f.second + 1;
    //                 if (temp < amount) {
    //                     q.push({temp, layer});
    //                     // std::cout << "amount:" << temp << " layer:" << layer << '\t';
    //                     m[temp] = layer;
    //                 }
    //             }
    //         }
    //         // std::cout << '\n';
    //     }
    //     return -1;
    // }
    int coinChange(vector<int>& coins, int amount)
    {
        // dp[i] 表示凑齐i需要的最少的硬币数
        vector dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 1; i < amount + 1; i++) {
            for (auto j : coins) {
                if (j == i) {
                    dp[i] = 1;
                    continue;
                }
                if (j < i && dp[i - j] != -1) {
                    if (dp[i] == -1)
                        dp[i] = dp[i - j] + 1;
                    else
                        dp[i] = min(dp[i], dp[i - j] + 1);
                }
            }
        }
        return dp[amount];
    }
};
// @lc code=end
int main()
{
    Solution s;
    vector   v = {1, 2, 5};
    s.coinChange(v, 11);
    return 0;
}
