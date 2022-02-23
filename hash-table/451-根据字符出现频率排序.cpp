/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> charCount;
        for (auto& i : s) {
            charCount[i]++;
        }
        vector<pair<char, int>> temp;
        for (auto& it : charCount) {
            temp.push_back(it);
        }
        sort(temp.begin(), temp.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second;
        });
        string result = "";
        for (auto& i : temp) {
            result += string(i.second, i.first);
        }
        return result;
    }
};
// @lc code=end