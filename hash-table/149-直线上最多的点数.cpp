/*
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数
 */
#include <climits>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    // string floatToString(float a)
    // {
    //     ostringstream sss;
    //     sss << setiosflags(ios::fixed) << setprecision(10) << a;
    //     string s(sss.str());
    //     return s;
    // }
    // int maxPoints(vector<vector<int>>& points)
    // {
    //     int                        result = 1;
    //     unordered_map<string, int> kCount;
    //     for (int i = 0; i < points.size(); i++) {
    //         kCount.clear();
    //         for (int j = i + 1; j < points.size(); j++) {
    //             string k;
    //             if (points[i][1] - points[j][1] == 0)
    //                 k = "y=" + floatToString(points[i][1]);
    //             else if (points[i][0] - points[j][0] == 0)
    //                 k = "x=" + floatToString(points[i][0]);
    //             else
    //                 k = floatToString((float)(points[i][1] - points[j][1]) /
    //                                   (points[i][0] - points[j][0]));
    //             // printf("i:[%d,%d] j:[%d,%d] result:%d InALine:%d k:", points[i][0],
    //             points[i][1],
    //             //        points[j][0], points[j][1], result, kCount[k] + 2);
    //             // for (auto m : k)
    //             //     printf("%c", m);
    //             // printf("\n");
    //             result = max(result, ++kCount[k] + 1);
    //         }
    //     }
    //     return result;
    // }
    int gcd(int a, int b)   //最大公约数
    {
        return b == 0 ? a : gcd(b, a % b);
    }
    int maxPoints(vector<vector<int>>& points)
    {
        if (points.size() == 0)
            return 0;
        int result = 1;
        for (int i = 0; i < points.size(); i++) {
            unordered_map<string, int> kCount;
            for (int j = i + 1; j < points.size(); j++) {
                int    x      = points[i][0] - points[j][0];
                int    y      = points[i][1] - points[j][1];
                int    gcdNum = gcd(x, y);
                string key    = to_string(x / gcdNum) + "_" + to_string(y / gcdNum);
                result        = max(result, ++kCount[key] + 1);
            }
        }
        return result;
    }
};
// @lc code=end
int main()
{
    vector<vector<int>> temp = {{0, 0}, {5151, 5150}, {5152, 5151}};
    Solution().maxPoints(temp);
}