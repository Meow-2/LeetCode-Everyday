/*
 * @lc app=leetcode.cn id=1446 lang=cpp
 *
 * [1446] 连续字符
 */

// @lc code=start
class Solution
{
public:
    int maxPower(string s)
    {
        int maxEnergy = 1, nowEnergy = 1;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i - 1] == s[i])
                maxEnergy = max(maxEnergy, ++nowEnergy);
            else
                nowEnergy = 1;
        }
        return maxEnergy;
    }
};
// @lc code=end
