/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> patternStr;
        unordered_map<string, int>  strUsed;
        string                      p = "";
        int                         j = 0;
        for (auto i : pattern) {
            p = "";
            if (j >= s.length())
                return false;
            while (j < s.length() && s[j] != ' ')
                p += s[j++];
            j++;
            if (patternStr.find(i) == patternStr.end()) {
                if (strUsed[p] != 0)
                    return false;
                else {
                    strUsed[p]++;
                    patternStr[i] = p;
                }
            }
            else if (patternStr[i] != p)
                return false;
        }
        return j < s.length() ? false : true;
    }
};
// @lc code=end