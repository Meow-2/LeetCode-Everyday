/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string minWindow(string s, string t)
    {
        vector<int> goal(58, 0), cur(58, 0);
        int left = 0, right = 0, minLength = s.length() + 1, resultLeft = 0, resultRight = 0,
            count = 0, valid = 0;

        for (auto i : t) {
            if (!goal[i - 'A'])
                count++;
            goal[i - 'A']++;
        }
        while (right < s.length()) {
            if (goal[s[right] - 'A']) {
                cur[s[right] - 'A']++;
                if (cur[s[right] - 'A'] == goal[s[right] - 'A'])
                    valid++;
            }
            right++;
            // printf("[%d,%d)\n", left, right);
            while (valid == count) {
                if (right - left < minLength) {
                    minLength   = right - left;
                    resultRight = right;
                    resultLeft  = left;
                }
                if (goal[s[left] - 'A']) {
                    cur[s[left] - 'A']--;
                    if (cur[s[left] - 'A'] < goal[s[left] - 'A'])
                        valid--;
                }
                left++;
            }
        }
        return string(s.substr(resultLeft, resultRight - resultLeft));
    }
};
// @lc code=end