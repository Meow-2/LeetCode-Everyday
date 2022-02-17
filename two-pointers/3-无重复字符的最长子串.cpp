/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    // 滑动窗口+unordered_map
    // int lengthOfLongestSubstring(string s)
    // {
    //     int                      left, right, maxSubLength = 0;   //[left,right)
    //     unordered_map<char, int> currentStr;
    //     while (right < s.length()) {
    //         {
    //             while (currentStr[s[right]])
    //                 currentStr[s[left++]]--;
    //             currentStr[s[right++]]++;
    //             maxSubLength = max(maxSubLength, right - left);
    //         }
    //     }
    //     return maxSubLength;
    // }

    // 8bit ASCII 码表共有字符256个
    int lengthOfLongestSubstring(string s)
    {
        vector<int> charLocation(256, -1);   //用于字符在字符串中的位置
        int         left      = 0;
        int         right     = 0;   //[left,right)
        int         maxLength = 0;
        while (right < s.length()) {
            if (charLocation[s[right]] >= left)
                left = charLocation[s[right]] + 1;
            charLocation[s[right]] = right++;
            maxLength              = max(maxLength, right - left);
        }
        return maxLength;
    }
};
// @lc code=end
int test0[256] = {-1};
int main()
{
    int    test[256] = {-1};
    string s         = " ";
    for (int i = 0; i < 256; i++)
        cout << test0[i];
    for (int i = 0; i < 256; i++)
        cout << test[i];
    cout << Solution().lengthOfLongestSubstring(s) << endl;
}