/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */
#include <unordered_map>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool backtrack(int i, unordered_map<int, unordered_set<int>>& p, unordered_set<int>& hasSearch,
                   unordered_set<int>& curPath)
    {
        if (curPath.count(i))
            return false;
        if (hasSearch.count(i))
            return true;
        curPath.insert(i);
        hasSearch.insert(i);
        for (auto j : p[i]) {
            if (!backtrack(j, p, hasSearch, curPath))
                return false;
        }
        curPath.erase(i);
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        unordered_set<int>                     hasSearch;
        unordered_set<int>                     curPath;
        unordered_map<int, unordered_set<int>> p;
        for (auto& i : prerequisites)
            p[i[0]].insert(i[1]);
        for (int i = 0; i < numCourses; i++) {
            if (!hasSearch.count(i))
                if (!backtrack(i, p, hasSearch, curPath))
                    return false;
        }
        return true;
    }
};
// @lc code=end
