/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        int i = 0;
        for (i = 0; i < wordList.size(); i++) {
            if (endWord == wordList[i])
                break;
        };
        if (i == wordList.size())
            return 0;
        vector<bool>             isVisited(wordList.size(), false);
        queue<pair<string, int>> currStrAndStep{{{beginWord, 1}}};
        while (!currStrAndStep.empty()) {
            auto&  curr     = currStrAndStep.front();
            string currStr  = curr.first;
            int    currStep = curr.second;
            currStrAndStep.pop();
            if (currStr == endWord)
                return currStep;
            int i = 0;
            for (i = 0; i < wordList.size(); i++) {
                if (!isVisited[i] && wordList[i].size() == currStr.size()) {
                    int count = 0;
                    for (int j = 0; j < currStr.size() && count < 2; j++) {
                        if (wordList[i][j] - currStr[j])
                            count++;
                    }
                    if (count == 1) {
                        currStrAndStep.push({wordList[i], currStep + 1});
                        isVisited[i] = true;
                    }
                }
            }
        }
        return 0;
    }
};
// @lc code=end
