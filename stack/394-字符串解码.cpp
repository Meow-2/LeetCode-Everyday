/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */
#include <stack>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string decodeString(string s)
    {
        string res;
        for (auto ch : s) {
            if (ch != ']')
                res.push_back(ch);
            else {
                string temp;
                while (res[res.size() - 1] != '[') {
                    temp.insert(temp.begin(), res[res.size() - 1]);
                    res.pop_back();
                }
                res.pop_back();
                int count = 1;
                int num   = 0;
                while (res.size() > 0 && res[res.size() - 1] >= '0' && res[res.size() - 1] <= '9') {
                    num += count * (res[res.size() - 1] - '0');
                    count *= 10;
                    res.pop_back();
                }
                for (int i = 0; i < num; i++) {
                    res += temp;
                }
            }
        }
        return res;
    }
};
// @lc code=end
int main()
{
    Solution a;
    a.decodeString("3[a]2[bc]");
    return -1;
}
