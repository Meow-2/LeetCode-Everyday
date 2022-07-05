/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

#include <cstddef>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    // 用index和cur_char可以确定一个节点, 深度优先是到达一个节点时才做事
    // path 的记录在刚刚到达节点时, 故而不需要回溯
    // void dfs(int index, int max_depth, string const& digits, char cur_char, vector<string>& res,
    //          unordered_map<char, string>& dict, string path)
    // {
    //     if (cur_char != NULL)
    //         path += cur_char;
    //     if (index + 1 == max_depth) {
    //         res.push_back(path);
    //         return;
    //     }
    //     for (auto const& ch : dict[digits[index + 1]]) {
    //         dfs(index + 1, max_depth, digits, ch, res, dict, path);
    //     }
    //     return;
    // }
    // vector<string> letterCombinations(string digits)
    // {
    //     if (digits.size() == 0)
    //         return {};
    //     unordered_map<char, string> dict = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
    //                                         {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
    //                                         {'8', "tuv"}, {'9', "wxyz"}};
    //     vector<string>              res;
    //     string                      path;
    //     int                         max_depth = digits.size();
    //     dfs(-1, max_depth, digits, NULL, res, dict, path);
    //     return res;
    // }

    // 单个 index 无法确定一个节点,只能确定是哪一层, 回溯是选择下一步的路径的过程中做事(树的支干)
    // 选择的过程会改变path, 所以需要回溯
    void backtrack(int index, int max_depth, string const& digits, vector<string>& res,
                   unordered_map<char, string>& dict, string& path)
    {
        if (index == max_depth) {
            res.push_back(path);
            return;
        }
        for (auto const& ch : dict[digits[index]]) {
            path.push_back(ch);
            backtrack(index + 1, max_depth, digits, res, dict, path);
            path.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
            return {};
        unordered_map<char, string> dict = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                                            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                                            {'8', "tuv"}, {'9', "wxyz"}};
        vector<string>              res;
        string                      path;
        int                         max_depth = digits.size();
        backtrack(0, max_depth, digits, res, dict, path);
        return res;
    }
};
// @lc code=end
