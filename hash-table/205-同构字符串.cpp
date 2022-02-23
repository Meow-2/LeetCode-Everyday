/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        unordered_map<char, char> sToT;
        unordered_map<char, int>  charUsed;
        for (int i = 0; i < s.length(); i++) {
            if (sToT.find(s[i]) == sToT.end()) {
                if (charUsed[t[i]] == 0) {
                    charUsed[t[i]]++;
                    sToT[s[i]] = t[i];
                }
                else
                    return false;
            }
            else if (sToT[s[i]] != t[i])
                return false;
        }
        return true;
    }
};
// @lc code=end