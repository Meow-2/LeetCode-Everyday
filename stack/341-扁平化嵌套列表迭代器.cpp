// @before-stub-for-debug-begin
#include "commoncppproblem341.h"

#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=341 lang=cpp
 *
 * [341] 扁平化嵌套列表迭代器
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

// class NestedIterator
// {
// public:
//     NestedIterator(vector<NestedInteger>& nestedList)
//     {
//         vector<NestedInteger> temp;
//         for (auto i = nestedList.rbegin(); i != nestedList.rend(); i++) {
//             temp.push_back(*i);
//         }
//         while (!temp.empty()) {
//             auto i = temp.back();
//             temp.pop_back();
//             if (i.isInteger())
//                 res.push_back(i.getInteger());
//             else {
//                 auto k = i.getList();
//                 for (auto j = k.rbegin(); j != k.rend(); j++)
//                     temp.push_back(*j);
//             }
//         }
//         cur = res.begin();
//     }
//
//     int next()
//     {
//         return *cur++;
//     }
//
//     bool hasNext()
//     {
//         return cur != res.end();
//     }
//
// private:
//     vector<int>::iterator cur;
//     vector<int>           res{};
// };

class NestedIterator
{
private:
    // pair 中存储的是列表的当前遍历位置，以及一个尾后迭代器用于判断是否遍历到了列表末尾
    stack<pair<vector<NestedInteger>::iterator, vector<NestedInteger>::iterator>> stk;

public:
    NestedIterator(vector<NestedInteger>& nestedList)
    {
        stk.emplace(nestedList.begin(), nestedList.end());
    }

    int next()
    {
        // 由于保证调用 next 之前会调用
        // hasNext，直接返回栈顶列表的当前元素，然后迭代器指向下一个元素
        return stk.top().first++->getInteger();
    }

    bool hasNext()
    {
        while (!stk.empty()) {
            auto& p = stk.top();
            if (p.first == p.second) {   // 遍历到当前列表末尾，出栈
                stk.pop();
                continue;
            }
            if (p.first->isInteger()) {
                return true;
            }
            // 若当前元素为列表，则将其入栈，且迭代器指向下一个元素
            auto& lst = p.first++->getList();
            stk.emplace(lst.begin(), lst.end());
        }
        return false;
    }
};
/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end
