/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

#include <algorithm>
#include <iterator>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    // 暴力解法超时
    // bool isSame(string a, string b)
    // {
    //     if (a.length() != b.length())
    //         return false;
    //     vector<int> charCount(26, 0);
    //     for (auto ch : a)
    //         charCount[ch - 'a']++;
    //     for (auto ch : b)
    //         if (--charCount[ch - 'a'] < 0)
    //             return false;
    //     return true;
    // }
    // vector<vector<string>> groupAnagrams(vector<string>& strs)
    // {
    //     vector<vector<string>> result;
    //     for (auto& str : strs) {
    //         bool ifPush = true;
    //         for (auto& vec : result) {
    //             if (isSame(str, vec[0])) {
    //                 vec.push_back(str);
    //                 ifPush = false;
    //             }
    //         }
    //         if (ifPush)
    //             result.push_back({str});
    //     }
    //     return result;
    // }
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>>     result;
        unordered_map<string, int> map;
        for (auto& str : strs) {
            string temp = str;
            sort(temp.begin(), temp.end());
            auto it = map.find(temp);
            if (it != map.end())
                result[it->second].push_back(str);
            else {
                result.push_back({str});
                map.insert({temp, result.size() - 1});
            }
        }
        return result;
    }
};
// @lc code=end
