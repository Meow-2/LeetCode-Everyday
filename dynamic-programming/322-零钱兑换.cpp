/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    int coinChange(vector<int>& coins, int amount)
    {
        if (!amount)
            return 0;
        int                           this_layer = 0;
        int                           next_layer = 0;
        unordered_map<long long, int> m;
        queue<pair<long long, int>>   q;
        for (auto i : coins) {
            if (i == amount)
                return 1;
            q.push({i, 1});
            // std::cout << "amount:" << i << " layer:" << 1 << '\t';
            m[i] = 1;
            next_layer++;
        }
        std::cout << '\n';
        while (!q.empty()) {
            this_layer = next_layer;
            next_layer = 0;
            for (int i = 0; i < this_layer; i++) {
                auto f = q.front();
                q.pop();
                for (auto i : coins) {
                    long long temp  = f.first + i;
                    int       layer = f.second + 1;
                    if (m.count(temp) && m[temp] <= layer)
                        continue;
                    if (temp == amount)
                        return f.second + 1;
                    if (temp < amount) {
                        q.push({temp, layer});
                        // std::cout << "amount:" << temp << " layer:" << layer << '\t';
                        m[temp] = layer;
                        next_layer++;
                    }
                }
            }
            // std::cout << '\n';
        }
        return -1;
    }
};
// @lc code=end
int main()
{
    Solution s;
    vector   v = {159, 342, 471, 125, 269, 151, 310, 485, 471, 356};
    s.coinChange(v, 6229);
    return 0;
}
