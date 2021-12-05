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
        string ans = "";
        for (auto x : s)
        {
            if (x == ' ')
                count++;
            if (count == k)
                break;
            ans += x;
        }

        return ans;
    }
};
// @lc code=end
