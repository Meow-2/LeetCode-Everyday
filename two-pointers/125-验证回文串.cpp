/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    bool isCh(char c)
    {
        if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
            return true;
        return false;
    }
    bool isNumOrCh(char c)
    {
        if (('0' <= c && c <= '9') || ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
            return true;
        return false;
    }
    bool isSame(char c, char c1)
    {
        if (c == c1)
            return true;
        if (abs(c - c1) == 32 && isCh(c) && isCh(c1))
            return true;
        else
            return false;
    }
    bool isPalindrome(string s)
    {
        int i = 0, j = s.length() - 1;
        while (i <= j) {
            for (i = i; !isNumOrCh(s[i]) && i <= j; i++)
                ;
            for (j = j; !isNumOrCh(s[j]) && i <= j; j--)
                ;
            if (i > j)
                break;
            cout << s[i] << " " << s[j] << endl;
            if (!isSame(s[i], s[j]))
                return false;
            i++;
            j--;
        }
        return true;
    }
};
// @lc code=end

int main()
{
    string s = "Zeus was deified, saw Suez.";
    Solution().isPalindrome(s);
}