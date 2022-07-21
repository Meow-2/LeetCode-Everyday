/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */
#include <iterator>
#include <set>
#include <unordered_map>
// #include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    // union-found, 只有当uf[i] = i 时, i 才是根
    unordered_map<int, int> uf;
    // union-found, 只有当sz[i] = i 时, size才有效, 才表示 union-found 的大小
    unordered_map<int, int> sz;

    int find(int x)
    {
        // 这里本可以直接写`uf[x] == x ? x : find(uf[x])` , 之所以这么写是为了优化路径
        return uf[x] == x ? x : uf[x] = find(uf[x]);
    }
    int merge(int x, int y)
    {
        x = find(x), y = find(y);
        // 如果根相同, 则什么也不做
        if (x == y)
            return sz[x];
        uf[y] = x;
        sz[x] = sz[x] + sz[y];
        return sz[x];
    }
    int longestConsecutive(vector<int>& nums)
    {
        int ans = nums.size() ? 1 : 0;
        for (auto& i : nums) {
            if (uf.count(i))
                continue;
            uf[i] = i;
            sz[i] = 1;
            if (uf.count(i - 1))
                ans = max(ans, merge(i - 1, i));
            if (uf.count(i + 1))
                ans = max(ans, merge(i, i + 1));
        }
        return ans;
    }
};
// @lc code=end