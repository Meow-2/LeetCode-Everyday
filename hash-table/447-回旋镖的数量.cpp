/*
 * @lc app=leetcode.cn id=447 lang=cpp
 *
 * [447] 回旋镖的数量
 */

#include <cmath>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numberOfBoomerangs(vector<vector<int>>& points)
    {
        int                     result = 0;
        unordered_map<int, int> distanceCount;
        for (auto& i : points) {
            distanceCount.clear();
            for (auto& j : points) {
                if (i != j) {
                    int temp = pow(i[0] - j[0], 2) + pow(i[1] - j[1], 2);
                    result += 2 * distanceCount[temp];
                    distanceCount[temp]++;
                }
            }
        }
        return result;
    }
};
// @lc code=end
