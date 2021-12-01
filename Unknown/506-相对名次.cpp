/*
 * @lc app=leetcode.cn id=506 lang=cpp
 *
 * [506] 相对名次
 */

// @lc code=start
#include <map>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        vector<string> medal(score.size(), "");
        map<int, int> order;
        for (int i = 0; i < score.size(); i++)
            order[-score[i]] = i;
        int i = 1;
        for (const auto &person : order)
        {
            switch (i)
            {
            case 1:
                medal[person.second] = "Gold Medal";
                break;
            case 2:
                medal[person.second] = "Silver Medal";
                break;
            case 3:
                medal[person.second] = "Bronze Medal";
                break;
            default:
                medal[person.second] = to_string(i);
                break;
            }
            i++;
        }
        return medal;
    }
};
// @lc code=end
