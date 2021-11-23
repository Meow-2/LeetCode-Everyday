/*
 * @lc app=leetcode.cn id=859 lang=cpp
 *
 * [859] 亲密字符串
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    bool buddyStrings(string s, string goal)
    {
        vector<int> chars;
        int sLength = s.size();
        int goalLength = goal.size();
        if (sLength != goalLength)
            return false;
        //也可以使用临时set来判断字符串里是否有相同元素
        //set里的元素是唯一的，可以快速去重，set<char>(s.begin(),s.end())
        unordered_map<char, int> hashMap;
        if (s == goal)
        {
            for (int i = 0; i < sLength; i++)
            {
                if (hashMap.find(s[i]) == hashMap.end())
                    hashMap.insert(make_pair(s[i], i));
                else
                    return true;
            }
            return false;
        }
        for (int i = 0; i < sLength; i++)
        {
            if (s[i] != goal[i])
            {
                if (chars.size() < 4)
                {
                    chars.push_back(s[i]);
                    chars.push_back(goal[i]);
                }
                else
                    return false;
            }
        }
        if (chars.size() == 4 && chars[0] == chars[3] && chars[1] == chars[2])
            return true;
        else
            return false;
    }
};
// @lc code=end
