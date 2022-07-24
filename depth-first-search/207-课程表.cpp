/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    // bool backtrack(int i, unordered_map<int, unordered_set<int>>& p, unordered_set<int>&
    // hasSearch,
    //                unordered_set<int>& curPath)
    // {
    //     if (curPath.count(i))
    //         return false;
    //     if (hasSearch.count(i))
    //         return true;
    //     curPath.insert(i);
    //     hasSearch.insert(i);
    //     for (auto j : p[i]) {
    //         if (!backtrack(j, p, hasSearch, curPath))
    //             return false;
    //     }
    //     curPath.erase(i);
    //     return true;
    // }
    // bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    // {
    //     unordered_set<int>                     hasSearch;
    //     unordered_set<int>                     curPath;
    //     unordered_map<int, unordered_set<int>> p;
    //     for (auto& i : prerequisites)
    //         p[i[0]].insert(i[1]);
    //     for (int i = 0; i < numCourses; i++) {
    //         if (!hasSearch.count(i))
    //             if (!backtrack(i, p, hasSearch, curPath))
    //                 return false;
    //     }
    //     return true;
    // }

    // 存储一个点有没有被访问过用数组就可以了, 用unordered_set因为需要计算哈希值所以会比较慢
    bool backtrack(int i, vector<vector<int>>& p, vector<int>& hasSearch)
    {
        if (hasSearch[i] == 1)
            return false;
        if (hasSearch[i] == 2)
            return true;
        hasSearch[i] = 1;
        for (auto j : p[i]) {
            if (!backtrack(j, p, hasSearch))
                return false;
        }
        hasSearch[i] = 2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<int> hasSearch(numCourses, 0);
        vector      p(numCourses, vector<int>());
        for (auto& i : prerequisites)
            p[i[0]].push_back(i[1]);
        for (int i = 0; i < numCourses; i++) {
            if (!hasSearch[i])
                if (!backtrack(i, p, hasSearch))
                    return false;
        }
        return true;
    }
};
// @lc code=end
