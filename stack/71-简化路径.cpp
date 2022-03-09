#include <iostream>
#include <ostream>
#include <stack>
#include <string>
#include <type_traits>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
class Solution
{
public:
    string simplifyPath(string path)
    {
        string result = "";
        path += '/';
        for (auto ch : path) {
            if (ch == '/' && result.length() > 0) {
                if (result[result.length() - 1] == '/')
                    continue;
                if (result[result.length() - 1] == '.' && result[result.length() - 2] == '/') {
                    result.pop_back();
                    continue;
                }
                if (result[result.length() - 1] == '.' && result.length() > 2 &&
                    result[result.length() - 2] == '.' && result[result.length() - 3] == '/') {
                    result.pop_back();
                    result.pop_back();
                    if (result.length() == 1) {}
                    else {
                        result.pop_back();
                        while (result[result.length() - 1] != '/')
                            result.pop_back();
                    }
                    continue;
                }
            }
            result += ch;
        }
        if (result.length() > 1 && result[result.length() - 1] == '/')
            result.pop_back();
        return result;
    }
};
// @lc code=end
int main(int argc, char* argv[])
{
    cout << Solution().simplifyPath("/./") << endl;
    return 0;
}
