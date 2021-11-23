// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem423.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=423 lang=cpp
 *
 * [423] 从英文中重建数字
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;
class Solution
{
private:
    unordered_map<char, int> hashMap;
    map<char, int> nums;
    void hashMapSecondDec(char c)
    {
        hashMap[c]--;
        if (hashMap[c] == 0)
            hashMap.erase(c);
    }
    void findNum(char c, char num, int n, string s)
    {
        for (int count = 1; hashMap.find(c) != hashMap.end(); count++)
        {
            nums[num] = count;
            for (int i = 0; i < s.size(); i++)
                hashMapSecondDec(s[i]);
        }
    }

public:
    string originalDigits(string s)
    {
        //头一次只超过了百分之10，不应该啊，到底是哪里的问题。。
        if (s == "")
            return "";
        for (int i = 0; i < s.size(); i++)
        {
            if (hashMap.find(s[i]) == hashMap.end())
            {
                hashMap.insert(make_pair(s[i], 1));
            }
            else
                hashMap[s[i]]++;
        }
        string temp = "";
        findNum('z', '0', 4, "zero");
        findNum('w', '2', 3, "two");
        findNum('u', '4', 4, "four");
        findNum('x', '6', 3, "six");
        findNum('g', '8', 5, "eight");
        findNum('o', '1', 3, "one");
        findNum('t', '3', 5, "three");
        findNum('f', '5', 4, "five");
        findNum('s', '7', 5, "seven");
        findNum('i', '9', 4, "nine");
        for (auto num : nums)
        {
            string tempp(num.second, num.first);
            temp += tempp;
        }
        return temp;
    }
};
// @lc code=end
