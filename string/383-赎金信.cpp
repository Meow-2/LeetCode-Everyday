/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int hashMap[26] = {0};
        for (char c : magazine)
        {
            hashMap[c - 'a']++;
        }
        for (char c : ransomNote)
        {
            if (hashMap[c - 'a'] > 0)
                hashMap[c - 'a']--;
            else
                return false;
        }
        return true;
    }
};
// @lc code=end
