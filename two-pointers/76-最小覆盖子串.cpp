/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include <array>
#include <climits>
#include <map>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    template<int T>
    bool isCover(array<int, T> const& a, array<int, T> const& b)
    {
        for (int i = 0; i < T; i++) {
            if (a[i] < b[i])
                return false;
        }
        return true;
    }
    string minWindow(string s, string t)
    {
        array<int, 58> t_char_count;
        array<int, 58> s_char_count;
        int            minLength = INT_MAX;
        int            minLeft   = -1;
        int            minRight  = -1;
        t_char_count.fill(0);
        s_char_count.fill(0);
        for (auto i : t) {
            t_char_count[i - 'A']++;
        }
        int left = 0, right = 0;
        // [left,right)为子串
        while (right < s.size()) {
            s_char_count[s[right] - 'A']++;
            right++;
            if (isCover<58>(s_char_count, t_char_count)) {
                do {
                    s_char_count[s[left] - 'A']--;
                    left++;
                } while (isCover<58>(s_char_count, t_char_count));
                if (minLength > right - left + 1) {
                    minLength = right - left + 1;
                    minLeft   = left - 1;
                    minRight  = right;
                }
            }
        }
        return minLeft == -1 ? "" : string(s.begin() + minLeft, s.begin() + minRight);
    }
};
// @lc code=end
