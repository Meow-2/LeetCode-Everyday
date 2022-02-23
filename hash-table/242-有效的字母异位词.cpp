/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> sMap;
        int                      valid = 0;
        for (auto ch : s) {
            sMap[ch]++;
        }
        int count = sMap.size();
        for (auto ch : t) {
            if (sMap[ch] == 0)
                return false;
            else if (--sMap[ch] == 0)
                valid++;
        }
        return count == valid ? true : false;
    }
};
// @lc code=end
