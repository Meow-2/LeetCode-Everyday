/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start
#include <string>
using namespace std;
class Solution
{
public:
    string reverseVowels(string s)
    {
        int i = 0, j = s.length();
        while (i < j) {
            for (i = i; i < j && !isMeta(s[i]); i++)
                ;
            for (j = j; i < j && !isMeta(s[j]); j--)
                ;
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }

private:
    bool isMeta(char c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        return false;
    }
};
// @lc code=end
