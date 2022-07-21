/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    // dfs 超时
    // bool wordBreak(string s, vector<string>& wordDict)
    // {
    //     if (s.size() == 0)
    //         return true;
    //     for (auto& i : wordDict) {
    //         int j;
    //         for (j = 0; j < s.size() && j < i.size() && s[j] == i[j]; j++)
    //             ;
    //         if (j == i.size() && wordBreak(string(s.begin() + j, s.end()), wordDict))
    //             return true;
    //     }
    //     return false;
    // }

    bool dfs(string s, vector<string>& wordDict, unordered_map<string, bool>& common)
    {
        // for (auto& i : common)
        //     cout << "string: " << i.first << " bool: " << i.second << '\n';
        if (s.size() == 0)
            return true;
        if (common.count(s))
            return common[s];
        for (auto& i : wordDict) {
            int j;
            for (j = 0; j < s.size() && j < i.size() && s[j] == i[j]; j++)
                ;
            if (j == i.size() && dfs(string(s.begin() + j, s.end()), wordDict, common)) {
                common[s] = true;
                return true;
            }
        }
        common[s] = false;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict)
    {
        unordered_map<string, bool> common;
        return dfs(s, wordDict, common);
    }

    // dp
    // bool wordBreak(string s, vector<string>& wordDict)
    // {
    //     unordered_set<string> se(wordDict.begin(), wordDict.end());
    //     int                   n = s.size();
    //     // dp[i]表示s的前i个字符能否被表示
    //     vector<bool> dp(n + 1, false);
    //     dp[0] = true;
    //     for (int i = 1; i < n + 1; i++) {
    //         dp[i] = false;
    //         for (int j = 0; j < i; j++) {
    //             if (dp[j] && se.count(s.substr(j, i - j)))
    //                 dp[i] = true;
    //         }
    //     }
    //     return dp[n];
    // }
};
// @lc code=end
