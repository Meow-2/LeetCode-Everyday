/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution
{
public:
    // dp
    // int numSquares(int n)
    // {
    //     vector<int> f(n + 1);
    //     for (int i = 1; i < n + 1; i++) {
    //         int minfn = INT_MAX;
    //         for (int j = 1; j * j <= i; j++) {
    //             minfn = min(minfn, 1 + f[i - static_cast<int>(pow(j, 2))]);
    //         }
    //         f[i] = minfn;
    //     }
    //     return f[n];
    // }

    // bfs
    int numSquares(int n)
    {
        queue<pair<int, int>> bfs{{{n, 0}}};
        // 去除图中的重复遍历节点
        vector<bool> ifHas(n, false);
        while (!bfs.empty()) {
            auto& node    = bfs.front();
            int   numNow  = node.first;
            int   stepNow = node.second;
            bfs.pop();
            if (numNow == 0)
                return stepNow;
            for (int i = 1; i * i <= numNow; i++) {
                int temp = numNow - static_cast<int>(pow(i, 2));
                if (!ifHas[temp]) {
                    bfs.push({numNow - static_cast<int>(pow(i, 2)), stepNow + 1});
                    ifHas[temp] = true;
                }
            }
        }
        throw invalid_argument("No Solution");
    }
};
// @lc code=end
