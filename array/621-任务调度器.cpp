/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start

ostream& operator<<(ostream& x, map<char, int> const& y)
{
    for (auto const& i : y)
        x << "[key: " << i.first << ", value: " << i.second << "] ";
    return x;
}

ostream& operator<<(ostream& x, set<int> const& y)
{
    for (auto const& i : y)
        x << i << ' ';
    return x;
}
class Solution
{
public:
    // 算法不对
    // int leastInterval(vector<char>& tasks, int n)
    // {
    //     map<char, int> taskToCount;
    //     for (auto ch : tasks) {
    //         taskToCount[ch]++;
    //     }
    //     vector<pair<char, int>> temp(taskToCount.begin(), taskToCount.end());
    //     sort(temp.begin(), temp.end(),
    //          [](auto const& x, auto const& y) { return x.second > y.second; });
    //     taskToCount = map<char, int>(temp.begin(), temp.end());
    //     set<int> hasUsed;
    //     int      index = 1;
    //     int      res   = INT_MIN;
    //     cout << taskToCount << '\n';
    //     for (auto i : taskToCount) {
    //         for (int j = 0; j < i.second; j++) {
    //             int temp = index + j * (n + 1);
    //             res      = max(res, temp);
    //             hasUsed.insert(temp);
    //             // hasUsed.count()
    //         }
    //         cout << hasUsed << '\n';
    //         while (hasUsed.count(index))
    //             index++;
    //     }
    //     return res;
    // }
    int leastInterval(vector<char>& tasks, int n)
    {
        int res{1};
        // 任务次数
        unordered_map<char, int> m;
        for (auto i : tasks)
            m[i]++;
        vector      nextTime(m.size() + 1, 1);
        vector<int> restCount;
        restCount.push_back(0);
        for (auto const& i : m)
            restCount.push_back(i.second);
        int taskCount = static_cast<int>(tasks.size());
        while (taskCount > 0) {
            int nextTask = 0;
            for (int j = 1; j < nextTime.size(); j++)
                if (restCount[j] > 0 && restCount[j] > restCount[nextTask] && nextTime[j] <= res)
                    nextTask = j;
            if (nextTask) {
                nextTime[nextTask] = res + n + 1;
                restCount[nextTask]--;
                taskCount--;
            }
            cout << taskCount << '\n';
            res++;
        }
        return res - 1;
    }
};
// @lc code=end
int main()
{
    Solution     a;
    vector<char> v = {'A', 'A', 'A', 'B', 'B', 'B'};
    a.leastInterval(v, 2);
    return 0;
}