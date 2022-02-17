/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    // 2021
    // bool isEmpty(int arr[])
    // {
    //     for (int i = 0; i < 26; i++) {
    //         if (arr[i] != 0)
    //             return false;
    //     }
    //     return true;
    // }
    //
    // vector<int> findAnagrams(string s, string p)
    // {
    //     int         diff[26] = {0};
    //     vector<int> temp;
    //     int         sLength = s.size();
    //     int         pLength = p.size();
    //     if (sLength < pLength)
    //         return {};
    //     for (int i = 0; i < pLength; i++) {
    //         diff[p[i] - 'a']--;
    //         diff[s[i] - 'a']++;
    //     }
    //     int index = 0;
    //     do {
    //         if (isEmpty(diff))
    //             temp.push_back(index);
    //         if (index == sLength - pLength)
    //             break;
    //         diff[s[index] - 'a']--;
    //         diff[s[index + pLength] - 'a']++;
    //         index++;
    //     } while (true);
    //     return temp;
    // }

    vector<int> findAnagrams(string s, string p)
    {
        vector<int> goal(26), cur(26), res;
        for (char c : p)
            goal[c - 'a']++;
        for (int i = 0; i < s.size(); i++) {
            cur[s[i] - 'a']++;
            if (i >= p.size())
                cur[s[i - p.size()] - 'a']--;
            if (cur == goal)
                res.push_back(i - p.size() + 1);
        }
        return res;
    }
};
// @lc code=end