/*
 * @lc app=leetcode.cn id=423 lang=cpp
 *
 * [423] 从英文中重建数字
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
    //看了最高票的解答，其实完全可以不需要 unordered_map，用字符的ASCII码和数组就能模拟 unordered_map<char,int>了，这个可以记下
public:
    string originalDigits(string s)
    {
        string num = "zowtufxsgi";
        int hashMap[123] = {}; // 123囊括这些字符的ASCII码
        for (auto ch : num)
            hashMap[ch] = 0;
        for (int i = 0; i < s.size(); i++)
            hashMap[s[i]]++;
        hashMap['o'] = hashMap['o'] - hashMap['z'] - hashMap['w'] - hashMap['u'];
        hashMap['t'] = hashMap['t'] - hashMap['w'] - hashMap['g'];
        hashMap['f'] = hashMap['f'] - hashMap['u'];
        hashMap['s'] = hashMap['s'] - hashMap['x'];
        hashMap['i'] = hashMap['i'] - hashMap['g'] - hashMap['f'] - hashMap['x'];
        string temp;
        for (int i = 0; i < num.size(); i++)
            temp += string(hashMap[num[i]], i + '0');
        return temp;
    }
};

// @lc code=end

// class Solution
// {
//     //知道是哪里的问题了，只需要输出数字就好了，根本就没必要每个数都清空。。。
//     //思路对了又没完全对。。。
//     //改完也只能超过百分之42，看来光有解题思路，没有编码思路也是不行的
// public:
//     string originalDigits(string s)
//     {
//         unordered_map<char, int> hashMap = {{'z', 0}, {'o', 0}, {'w', 0}, {'t', 0}, {'u', 0}, {'f', 0}, {'x', 0}, {'s', 0}, {'g', 0}, {'i', 0}};
//         for (int i = 0; i < s.size(); i++)
//             hashMap[s[i]]++;
//         hashMap['o'] = hashMap['o'] - hashMap['z'] - hashMap['w'] - hashMap['u'];
//         hashMap['t'] = hashMap['t'] - hashMap['w'] - hashMap['g'];
//         hashMap['f'] = hashMap['f'] - hashMap['u'];
//         hashMap['s'] = hashMap['s'] - hashMap['x'];
//         hashMap['i'] = hashMap['i'] - hashMap['g'] - hashMap['f'] - hashMap['x'];
//         string temp = string(hashMap['z'], '0') + string(hashMap['o'], '1') + string(hashMap['w'], '2') + string(hashMap['t'], '3') + string(hashMap['u'], '4') + string(hashMap['f'], '5') + string(hashMap['x'], '6') + string(hashMap['s'], '7') + string(hashMap['g'], '8') + string(hashMap['i'], '9');
//         return temp;
//     }
// };

// class Solution
// {
//         //头一次只超过了百分之10，不应该啊，到底是哪里的问题。。
// private:
//     unordered_hashMap<char, int> hashMap;
//     hashMap<char, int> nums;
//     void hashMapSecondDec(char c)
//     {
//         hashMap[c]--;
//         if (hashMap[c] == 0)
//             hashMap.erase(c);
//     }
//     void findNum(char c, char num, int n, string s)
//     {
//         for (int count = 1; hashMap.find(c) != hashMap.end(); count++)
//         {
//             nums[num] = count;
//             for (int i = 0; i < s.size(); i++)
//                 hashMapSecondDec(s[i]);
//         }
//     }

// public:
//     string originalDigits(string s)
//     {
//         if (s == "")
//             return "";
//         for (int i = 0; i < s.size(); i++)
//         {
//             if (hashMap.find(s[i]) == hashMap.end())
//             {
//                 hashMap.insert(make_pair(s[i], 1));
//             }
//             else
//                 hashMap[s[i]]++;
//         }
//         string temp = "";
//         findNum('z', '0', 4, "zero");
//         findNum('w', '2', 3, "two");
//         findNum('u', '4', 4, "four");
//         findNum('x', '6', 3, "six");
//         findNum('g', '8', 5, "eight");
//         findNum('o', '1', 3, "one");
//         findNum('t', '3', 5, "three");
//         findNum('f', '5', 4, "five");
//         findNum('s', '7', 5, "seven");
//         findNum('i', '9', 4, "nine");
//         for (auto num : nums)
//         {
//             string tempp(num.second, num.first);
//             temp += tempp;
//         }
//         return temp;
//     }
//};