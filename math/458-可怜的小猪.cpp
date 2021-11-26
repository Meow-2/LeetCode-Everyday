/*
 * @lc app=leetcode.cn id=458 lang=cpp
 *
 * [458] 可怜的小猪
 */
// @lc code=start
using namespace std;
class Solution
{
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest)
    {
        int time = floor(minutesToTest / minutesToDie) + 1;
        //loga(b) = log2(b)/log2(a);
        return ceil(log(buckets) / log(time));
    }
};
// @lc code=end
