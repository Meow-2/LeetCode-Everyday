/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (words.find(endWord) == words.end()) {
            return {};
        }
        //记录第一遍历到该节点的step（层数）
        int                                          step = 1;
        queue<string>                                bfs{{beginWord}};
        unordered_map<string, int>                   firstVisitAt{{{beginWord, step}}};
        unordered_map<string, unordered_set<string>> changedFrom;
        bool                                         found = false;
        while (!bfs.empty() && !found) {
            int num = bfs.size();
            while (num--) {
                auto curStr = bfs.front();
                for (auto& i : curStr) {
                    char temp = i;
                    for (int c = 'a'; c <= 'z'; c++) {
                        i = c;
                        if (curStr == endWord)
                            found = true;
                        if (words.find(curStr) != words.end()) {
                            if (!firstVisitAt.count(curStr)) {
                                bfs.push(curStr);
                                changedFrom[curStr].insert(bfs.front());
                                firstVisitAt[curStr] = step + 1;
                            }
                            else if (firstVisitAt[curStr] == step + 1) {
                                bfs.push(curStr);
                                changedFrom[curStr].insert(bfs.front());
                            }
                        }
                    }
                    i = temp;
                }
                bfs.pop();
            }
            step++;
        }
        if (!found)
            return {};
        vector<vector<string>> result;
        vector<string>         path({endWord});
        dfs(result, endWord, changedFrom, path);
        return result;
    }
    void dfs(vector<vector<string>>& res, const string& Node,
             unordered_map<string, unordered_set<string>>& from, vector<string>& path)
    {
        if (from[Node].empty()) {
            res.push_back({path.rbegin(), path.rend()});
            return;
        }
        for (const string& Parent : from[Node]) {
            path.push_back(Parent);
            dfs(res, Parent, from, path);
            path.pop_back();
        }
    }
};
// @lc code=end
