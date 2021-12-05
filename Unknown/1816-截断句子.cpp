/*
 * @lc app=leetcode.cn id=1816 lang=cpp
 *
 * [1816] 截断句子
 */

// @lc code=start
class Solution
{
public:
    string truncateSentence(string s, int k)
    {
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
                count++;
            if (count == k)
            {
                s.erase(i);
                return s;
            }
        }
        return s;
    }
};
// @lc code=end
